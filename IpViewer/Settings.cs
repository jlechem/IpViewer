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
using System;
using System.Windows.Forms;

namespace IpViewer2
{
    public partial class Settings : Form
    {
        /// <summary>
        /// 
        /// </summary>
        public Settings()
        {
            InitializeComponent();

            this.LoadSettings();

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.SaveSettings();
            this.Close();
        }

        /// <summary>
        /// Loads the control values from the settings.
        /// </summary>
        private void LoadSettings()
        {
            this.textBoxRefreshRate.Text = IpViewerSettings.Instance.RefreshTime.ToString();

            this.checkBoxCloseToTray.Checked = IpViewerSettings.Instance.CloseToTray;
            this.checkBoxGetExternalIP.Checked = IpViewerSettings.Instance.GetExternalAddress;
            this.checkBoxMinimizeToTray.Checked = IpViewerSettings.Instance.MinimizeToTray;
            this.checkBoxStartMinimized.Checked = IpViewerSettings.Instance.StartMinimized;
            this.checkBoxTopmost.Checked = IpViewerSettings.Instance.TopMost;
            this.checkBoxEnableLogging.Checked = IpViewerSettings.Instance.LoggingEnabled;
        }

        /// <summary>
        /// Saves the settings values from the controls.
        /// </summary>
        private void SaveSettings()
        {
            IpViewerSettings.Instance.RefreshTime = int.Parse(this.textBoxRefreshRate.Text);

            IpViewerSettings.Instance.CloseToTray = this.checkBoxCloseToTray.Checked;
            IpViewerSettings.Instance.GetExternalAddress = this.checkBoxGetExternalIP.Checked;
            IpViewerSettings.Instance.MinimizeToTray = this.checkBoxMinimizeToTray.Checked;
            IpViewerSettings.Instance.StartMinimized = this.checkBoxStartMinimized.Checked;
            IpViewerSettings.Instance.TopMost = this.checkBoxTopmost.Checked;
            IpViewerSettings.Instance.LoggingEnabled = this.checkBoxEnableLogging.Checked;
            IpViewerSettings.Instance.SaveSettings();

        }

    }
}
