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

namespace IViewer.BusinessObject
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
            }
            catch (Exception ex)
            {
                log.Error("An exception occured in GetAdapters().", ex);
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
                log.Error("An exception occured in GetHostInformation().", ex);
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

            return result;
        }

    }
}
