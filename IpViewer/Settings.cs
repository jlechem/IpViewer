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


using IPViewer.BusinessObject;
using log4net;
using System;
using System.Windows.Forms;
using IpViewer.BusinessObject;

namespace IpViewer2
{
    public partial class Settings : Form
    {
        #region Fields

        private static readonly ILog log = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        #endregion

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
            this.numericUpDownInterval.Value = IpViewerSettings.Instance.RefreshTime;

            var nodes = this.treeViewSettings.Nodes;

            try
            {
                nodes.Find("CloseToTray", true)[0].Checked = IpViewerSettings.Instance.CloseToTray;
                nodes.Find("MinimizeToTray", true)[0].Checked = IpViewerSettings.Instance.MinimizeToTray;
                nodes.Find("StartMinimized", true)[0].Checked = IpViewerSettings.Instance.StartMinimized;
                nodes.Find("Topmost", true)[0].Checked = IpViewerSettings.Instance.TopMost;
                nodes.Find("EnableLogging", true)[0].Checked = IpViewerSettings.Instance.LoggingEnabled;
                nodes.Find("LogExternalAddress", true)[0].Checked = IpViewerSettings.Instance.LogExternalIpAddress;
                nodes.Find("LogAdapterInformation", true)[0].Checked = IpViewerSettings.Instance.LogAdapterInformation;
                nodes.Find("IPAddress", true)[0].Checked = IpViewerSettings.Instance.LogAdapterIpAddress;
                nodes.Find("OperationalStatus", true)[0].Checked = IpViewerSettings.Instance.LogAdapterOperationalStatus;
                nodes.Find("Use12HourClock", true)[0].Checked = IpViewerSettings.Instance.Use12HourClock;

                this.Opacity = IpViewerSettings.Instance.Opacity;
                var temp = IpViewerSettings.Instance.Opacity * 100;
                this.trackBarOpacity.Value = (int)temp;
            }
            catch (Exception ex)
            {
                log.Error("An exception occurred in LoadSettings().", ex);
            }
        }

        /// <summary>
        /// Saves the settings values from the controls.
        /// </summary>
        private void SaveSettings()
        {
            this.numericUpDownInterval.Value = this.numericUpDownInterval.Value > 1440 ? this.numericUpDownInterval.Value : 1440;

            var nodes = this.treeViewSettings.Nodes;

            try
            {
                IpViewerSettings.Instance.CloseToTray = nodes.Find("CloseToTray", true)[0].Checked;
                IpViewerSettings.Instance.MinimizeToTray = nodes.Find("MinimizeToTray", true)[0].Checked;
                IpViewerSettings.Instance.StartMinimized = nodes.Find("StartMinimized", true)[0].Checked;
                IpViewerSettings.Instance.TopMost = nodes.Find("Topmost", true)[0].Checked;
                IpViewerSettings.Instance.LoggingEnabled = nodes.Find("EnableLogging", true)[0].Checked;
                IpViewerSettings.Instance.LogExternalIpAddress = nodes.Find("LogExternalAddress", true)[0].Checked;
                IpViewerSettings.Instance.LogAdapterInformation = nodes.Find("LogAdapterInformation", true)[0].Checked;
                IpViewerSettings.Instance.LogAdapterIpAddress = nodes.Find("IPAddress", true)[0].Checked;
                IpViewerSettings.Instance.LogAdapterOperationalStatus = nodes.Find("OperationalStatus", true)[0].Checked;
                IpViewerSettings.Instance.Use12HourClock = nodes.Find("Use12HourClock", true)[0].Checked;

                IpViewerSettings.Instance.Opacity = ((double)this.trackBarOpacity.Value / 100);

            }
            catch (Exception ex)
            {
                log.Error("An exception occurred in LoadSettings().", ex);
            }
            finally
            {
                IpViewerSettings.Instance.SaveSettings();
            }
        }

        private void trackBarOpacity_ValueChanged(object sender, EventArgs e)
        {
            this.Opacity = ((double) this.trackBarOpacity.Value / 100);
        }
    }
}