using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IpViewer.BusinessObject
{
    public class PacketInformation
    {
        public string Name { get; set; }

        public long Id { get; set; }

        public string Endpoint { get; set; }

        public short Size { get; set; }

    }
}