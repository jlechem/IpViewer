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

            this.comboBoxAdapters.SelectedIndex = 0;

        }

        /// <summary>
        /// Sets the main form's control values from the settings.
        /// </summary>
        private void SetFormControlValuesFromSettings()
        {
            this.TopMost = IpViewerSettings.Instance.TopMost;

            if( IpViewerSettings.Instance.StartMinimized)
            {
                this.ShowInTaskbar = false;
                this.WindowState = FormWindowState.Minimized;
            }
            else
            {
                this.ShowInTaskbar = true;
                this.WindowState = FormWindowState.Normal;
            }

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

    }
}
