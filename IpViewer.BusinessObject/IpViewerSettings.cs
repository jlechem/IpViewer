//   Copyright(C) 2020 Justin LECheminant


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

using System.Configuration;

namespace IpViewer.BusinessObject
{
    public class IpViewerSettings
    {
        #region

        public static IpViewerSettings _instance;

        public static object _lock = new object();

        #endregion

        public static IpViewerSettings Instance
        {
            get
            {
                lock (_lock)
                {
                    if (_instance == null)
                    {
                        _instance = new IpViewerSettings();
                        _instance.LoadSettings();

                    }
                }

                return _instance;
            }
        }

        private IpViewerSettings()
        {

        }

        #region Properties

        public bool Use12HourClock { get; set; }

        public bool GetExternalAddress { get; set; }

        public bool StartMinimized { get; set; }

        public bool LogExternalIpAddress { get; set; }

        public bool TopMost { get; set; }

        public bool CloseToTray { get; set; }

        public int RefreshTime { get; set; }

        public bool MinimizeToTray { get; set; }

        public bool LogAdapterOperationalStatus { get; set; }

        public string CurrentAdapterName { get; set; }

        public bool LoggingEnabled { get; set; }

        public bool LogAdapterInformation { get; set; }

        public bool LogAdapterIpAddress { get; set; }
        
        public bool LogIpAddress { get; set; }

        public double Opacity { get; set; }

        #endregion

        private void LoadSettings()
        {
            RefreshTime = int.Parse(ConfigurationManager.AppSettings["RefreshTime"]);
            Opacity = double.Parse(ConfigurationManager.AppSettings["Opacity"]);
            LoggingEnabled = bool.Parse(ConfigurationManager.AppSettings["LoggingEnabled"]);
            LogIpAddress = bool.Parse(ConfigurationManager.AppSettings["LogIpAddress"]);
            MinimizeToTray = bool.Parse(ConfigurationManager.AppSettings["MinimizeToTray"]);
            CloseToTray = bool.Parse(ConfigurationManager.AppSettings["CloseToTray"]);
            StartMinimized = bool.Parse(ConfigurationManager.AppSettings["StartMinimized"]);
            GetExternalAddress = bool.Parse(ConfigurationManager.AppSettings["GetExternalAddress"]);
            TopMost = bool.Parse(ConfigurationManager.AppSettings["Topmost"]);
            CurrentAdapterName = ConfigurationManager.AppSettings["CurrentAdapterName"];
            LogAdapterInformation = bool.Parse(ConfigurationManager.AppSettings["LogAdapterInformation"]);
            LogAdapterIpAddress = bool.Parse(ConfigurationManager.AppSettings["LogAdapterIpAddress"]);
            LogAdapterOperationalStatus = bool.Parse(ConfigurationManager.AppSettings["LogAdapterOperationalStatus"]);
            Use12HourClock = bool.Parse(ConfigurationManager.AppSettings["Use12HourClock"]);
        }

        public void SaveSettings()
        {
            var manager = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

            manager.AppSettings.Settings["RefreshTime"].Value = RefreshTime.ToString();
            manager.AppSettings.Settings["Opacity"].Value = Opacity.ToString();
            manager.AppSettings.Settings["LoggingEnabled"].Value = LoggingEnabled.ToString();
            manager.AppSettings.Settings["LogIpAddress"].Value = LogIpAddress.ToString();
            manager.AppSettings.Settings["MinimizeToTray"].Value = MinimizeToTray.ToString();
            manager.AppSettings.Settings["CloseToTray"].Value = CloseToTray.ToString();
            manager.AppSettings.Settings["StartMinimized"].Value = StartMinimized.ToString();
            manager.AppSettings.Settings["GetExternalAddress"].Value = GetExternalAddress.ToString();
            manager.AppSettings.Settings["Topmost"].Value = TopMost.ToString();
            manager.AppSettings.Settings["CurrentAdapterName"].Value = CurrentAdapterName;
            manager.AppSettings.Settings["LogAdapterInformation"].Value = LogAdapterInformation.ToString();
            manager.AppSettings.Settings["LogAdapterIpAddress"].Value = LogAdapterIpAddress.ToString();
            manager.AppSettings.Settings["LogAdapterOperationalStatus"].Value = LogAdapterOperationalStatus.ToString();
            manager.AppSettings.Settings["Use12HourClock"].Value = Use12HourClock.ToString();

            manager.Save(ConfigurationSaveMode.Full, true);
            ConfigurationManager.RefreshSection("appSettings");
        }

    }
}