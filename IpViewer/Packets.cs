using IpViewer.BusinessObject;
using System.Collections.Generic;
using System.Windows.Forms;
using IPViewer.BusinessObject;

namespace IpViewer
{
    public partial class Packets : Form
    {
        #region Fields

        private List<PacketInformation> _packets = new List<PacketInformation>();

        #endregion

        public Packets()
        {
            InitializeComponent();
        }

        public Packets(AdapterInfo ai)
        {
            InitializeComponent();

            this.labelAdapter.Text = ai.Name;

        }

        private void GetPackets()
        {
            // TODO: get the packets from the current adapter

            this.dataGridView1.DataSource = _packets;

        }


    }
}
