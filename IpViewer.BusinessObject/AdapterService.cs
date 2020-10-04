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

using log4net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Text;
using IpViewer.BusinessObject;

namespace IPViewer.BusinessObject
{
   public class AdapterService
    {
        #region Fields

        private static readonly ILog log = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        #endregion

        /// <summary>
        /// Gets the adapters for the current system.
        /// </summary>
        /// <returns></returns>
        public List<AdapterInfo> GetAdapters()
        {
            var result = new List<AdapterInfo>();

            try
            {
                var adapters = NetworkInterface.GetAllNetworkInterfaces();

                result.AddRange(adapters.Select(adapter =>
                    new AdapterInfo
                    {
                        Id = adapter.Id,
                        MacAddress = adapter.GetPhysicalAddress().ToString(),
                        IpAddress = adapter.GetIPProperties()?.UnicastAddresses?.FirstOrDefault()?.Address.ToString() ?? String.Empty,
                        SupportMulticast = adapter.SupportsMulticast,
                        Name = adapter.Name,
                        Description = adapter.Description,
                        Speed = adapter.Speed,
                        OperationalStatus = adapter.OperationalStatus.ToString()
                    }));

                if(IpViewerSettings.Instance.LoggingEnabled && IpViewerSettings.Instance.LogAdapterInformation)
                {
                    LogAdapterInfo(result);
                }
            }
            catch (Exception ex)
            {
                log.Error("An exception occurred in GetAdapters().", ex);
            }
            
            return result;
        }

        /// <summary>
        /// Gets the host information.
        /// </summary>
        /// <returns></returns>
        public HostInformation GetHostInformation()
        {
            var result = new HostInformation();

            try
            {
                var hostName = Dns.GetHostName(); 

                result.HostName = hostName;
                result.InternalIpAddress = Dns.GetHostEntry(hostName).AddressList[0].ToString();
                result.ExternalIpAddress = GetExternalIpAddress();
            }
            catch (Exception ex)
            {
                log.Error("An exception occurred in GetHostInformation().", ex);
            }

            return result;
        }

        /// <summary>
        /// Gets the external ip address.
        /// </summary>
        /// <returns></returns>
        private string GetExternalIpAddress()
        {
            var result = String.Empty;

            try
            {
                using (var client = new WebClient())
                {
                    result = client.DownloadString("http://ifconfig.me").Replace("\n", "");
                }
            }
            catch (Exception ex)
            {
                log.Error("An exception occured in GetExternalIpAddress().", ex);
            }

            if (IpViewerSettings.Instance.LoggingEnabled && IpViewerSettings.Instance.LogExternalIpAddress)
            {
                log.Info($"External IP Address: {result}");
            }

            return result;
        }

        /// <summary>
        /// Logs the adapter information.
        /// </summary>
        /// <param name="adapters"></param>
        private void LogAdapterInfo(List<AdapterInfo> adapters)
        {
            var logEntry = new StringBuilder();

            foreach( var adapter in adapters )
            {
                logEntry.Append($"{adapter.Name} -");

                if(IpViewerSettings.Instance.LogAdapterIpAddress)
                {
                    logEntry.Append($" IP Address: {adapter.IpAddress}");
                }

                if (IpViewerSettings.Instance.LogAdapterOperationalStatus)
                {
                    logEntry.Append($" Operational Status: {adapter.OperationalStatus}");
                }

                logEntry.Append(Environment.NewLine);
            }

            log.Info($"Adapter Information{Environment.NewLine}{logEntry}");
        }

    }
}
