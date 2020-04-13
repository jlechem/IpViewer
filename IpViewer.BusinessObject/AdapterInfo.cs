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

namespace IViewer.BusinessObject
{
    public class AdapterInfo
    {
        /// <summary>
        /// Gets or sets the adapter's identifier.
        /// </summary>
        public string Id { get; set; }

        /// <summary>
        /// Gets or sets the MAC address.
        /// </summary>
        public string MacAddress { get; set; }

        /// <summary>
        /// Gets or sets the operational status.
        /// </summary>
        public string OperationalStatus { get; set; }

        /// <summary>
        /// Gets or sets the adapter's IP address.
        /// </summary>
        public string IpAddress { get; set; }

        /// <summary>
        /// Gets or sets if the adapter supports multicast.
        /// </summary>
        public bool SupportMulticast { get; set; }

        /// <summary>
        /// Gets or sets the speed.
        /// </summary>
        public long Speed { get; set; }

        /// <summary>
        /// Gets or sets the name of the adapter.
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the adapter's description.
        /// </summary>
        public string Description { get; set; }

    }
}