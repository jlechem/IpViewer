using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace IpViewer.BusinessObject
{
    public class IpViewerSettings
    {
        public static IpViewerSettings _instance;

        public static object _lock = new object();
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

        private void LoadSettings()
        {
            RefreshTime = int.Parse(ConfigurationManager.AppSettings["RefreshTime"]);
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
        }

        public void SaveSettings()
        {
            var manager = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

            manager.AppSettings.Settings["RefreshTime"].Value = RefreshTime.ToString();
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

            manager.Save(ConfigurationSaveMode.Full, true);
            ConfigurationManager.RefreshSection("appSettings");
        }

    }
}