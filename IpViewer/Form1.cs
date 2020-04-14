//   IP Viewer, gets adapter and IP information about your system.
//   Copyright(C) 2020  Sasquatch Software

//   This program is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.

//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//   GNU General Public License for more details.

//   You should have received a copy of the GNU General Public License
//   along with this program.If not, see<https://www.gnu.org/licenses/>.

using IViewer.BusinessObject;
using log4net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace IpViewer2
{
    public partial class Form1 : Form
    {
        #region Fields

        private static readonly ILog log = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private List<AdapterInfo> _adapters = new List<AdapterInfo>();

        private HostInformation _hostInformation = new HostInformation();

        private AdapterService _adapterService = new AdapterService();

        private bool _closeFromContextMenu = false;
        #endregion
        
        /// <summary>
        /// 
        /// </summary>
        public Form1()
        {
            InitializeComponent();

            this.SetFormControlValuesFromSettings();

            this.GetIpInformation();

            this.SetHostInformationControls();

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                this.Cursor = Cursors.WaitCursor;

                new AboutBox1().ShowDialog();
            }
            finally
            {
                this.Cursor = Cursors.Default;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void comboBoxAdapters_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                this.Cursor = Cursors.WaitCursor;

                var currentAdapter = _adapters.FirstOrDefault(x => x.Name == ((ComboBox)sender) .Text );

                if( currentAdapter != null)
                {
                    SetAdapterInformationControls(currentAdapter);
                }
            }
            finally
            {
                this.Cursor = Cursors.Default;
            }
        }

        /// <summary>
        /// Sets the control information with the adapter data.
        /// </summary>
        /// <param name="adapterInfo"></param>
        private void SetAdapterInformationControls(AdapterInfo adapterInfo)
        {
            IpViewerSettings.Instance.CurrentAdapterName = adapterInfo.Name;
            IpViewerSettings.Instance.SaveSettings();

            this.labelMacAddress.Text = adapterInfo.MacAddress;
            this.labelSpeed.Text = adapterInfo.Speed.ToString();
            this.labelAdapterStatus.Text = adapterInfo.OperationalStatus;
            this.labelInternalAddress.Text = adapterInfo.IpAddress;
        }

        /// <summary>
        /// Sets the values for the host information controls.
        /// </summary>
        private void SetHostInformationControls()
        {
            this.labelHostName.Text = _hostInformation.HostName;
            this.labelInternalAddress.Text = _hostInformation.InternalIpAddress;
            this.labelExternalAddress.Text = _hostInformation.ExternalIpAddress;
        }

        /// <summary>
        /// Gets the ip information for the system.
        /// </summary>
        private void GetIpInformation()
        {
            _hostInformation = _adapterService.GetHostInformation();

            _adapters = _adapterService.GetAdapters();

            this.comboBoxAdapters.Items.AddRange(_adapters.Select(adapter => adapter.Name).ToArray());

            var index = 0;

            if (!String.IsNullOrWhiteSpace(IpViewerSettings.Instance.CurrentAdapterName))
            {
                foreach (var item in this.comboBoxAdapters.Items)
                {
                    if (item.ToString() == IpViewerSettings.Instance.CurrentAdapterName)
                    {
                        break;
                    }

                    index++;
                }
            }

            this.comboBoxAdapters.SelectedIndex = index >= this.comboBoxAdapters.Items.Count ? 0 : index;

            this.notifyIcon1.Text = _hostInformation.ExternalIpAddress;

            if (IpViewerSettings.Instance.LoggingEnabled && IpViewerSettings.Instance.LogIpAddress)
            {
                log.Info($"External IP Address: {_hostInformation.ExternalIpAddress}");
            }
        }

        /// <summary>
        /// Sets the main form's control values from the settings.
        /// </summary>
        private void SetFormControlValuesFromSettings()
        {
            this.TopMost = IpViewerSettings.Instance.TopMost;

            this.timer1.Interval = (int)IpViewerSettings.Instance.RefreshTime * 60000;

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void settingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                this.Cursor = Cursors.WaitCursor;

                var result = new Settings().ShowDialog();

                if( result == DialogResult.OK)
                {
                    this.SetFormControlValuesFromSettings();
                }
            }
            finally
            {
                this.Cursor = Cursors.Default;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void refreshIPInformationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                this.Cursor = Cursors.WaitCursor;

                this.GetIpInformation();

                this.SetHostInformationControls();
            }
            finally
            {
                this.Cursor = Cursors.Default;
            }

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.GetIpInformation();

            this.SetHostInformationControls();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            _closeFromContextMenu = true;

            this.Close();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!_closeFromContextMenu)
            {
                if (IpViewerSettings.Instance.CloseToTray)
                {
                    this.WindowState = FormWindowState.Minimized;
                    this.ShowInTaskbar = false;
                    e.Cancel = false;
                }
                else
                {
                    this.Close();
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void settingsToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            var result = new Settings().ShowDialog();

            if (result == DialogResult.OK)
            {
                this.SetFormControlValuesFromSettings();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Resize(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Minimized)
            {
                if (IpViewerSettings.Instance.MinimizeToTray)
                {
                    this.ShowInTaskbar = false;
                }
                else
                {
                    this.ShowInTaskbar = true;
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void notifyIcon1_DoubleClick(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
            this.ShowInTaskbar = true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {
            if (IpViewerSettings.Instance.StartMinimized)
            {
                this.WindowState = FormWindowState.Minimized;
                this.ShowInTaskbar = false;
            }
            else
            {
                this.WindowState = FormWindowState.Normal;
                this.ShowInTaskbar = true;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void copyExternalIPAddressToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(_hostInformation.ExternalIpAddress);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void copyInternalIPAddressToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(this.labelInternalAddress.Text);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void copyExternalAddressToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(_hostInformation.ExternalIpAddress);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            this.GetIpInformation();

            this.SetHostInformationControls();
        }

    }
}