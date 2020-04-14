namespace IpViewer2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.labelHostName = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.labelExternalAddress = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.labelInternalAddress = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.labelSpeed = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.labelMacAddress = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.labelAdapterStatus = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBoxAdapters = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.refreshIPInformationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.copyInternalIPAddressToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copyExternalIPAddressToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.labelHostName);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.labelExternalAddress);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Cursor = System.Windows.Forms.Cursors.Default;
            resources.ApplyResources(this.groupBox1, "groupBox1");
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.TabStop = false;
            // 
            // labelHostName
            // 
            resources.ApplyResources(this.labelHostName, "labelHostName");
            this.labelHostName.Name = "labelHostName";
            // 
            // label9
            // 
            resources.ApplyResources(this.label9, "label9");
            this.label9.Name = "label9";
            // 
            // labelExternalAddress
            // 
            resources.ApplyResources(this.labelExternalAddress, "labelExternalAddress");
            this.labelExternalAddress.Name = "labelExternalAddress";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.labelInternalAddress);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.labelSpeed);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.labelMacAddress);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.labelAdapterStatus);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.comboBoxAdapters);
            this.groupBox2.Controls.Add(this.label3);
            resources.ApplyResources(this.groupBox2, "groupBox2");
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.TabStop = false;
            // 
            // labelInternalAddress
            // 
            resources.ApplyResources(this.labelInternalAddress, "labelInternalAddress");
            this.labelInternalAddress.Name = "labelInternalAddress";
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // labelSpeed
            // 
            resources.ApplyResources(this.labelSpeed, "labelSpeed");
            this.labelSpeed.Name = "labelSpeed";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // labelMacAddress
            // 
            resources.ApplyResources(this.labelMacAddress, "labelMacAddress");
            this.labelMacAddress.Name = "labelMacAddress";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // labelAdapterStatus
            // 
            resources.ApplyResources(this.labelAdapterStatus, "labelAdapterStatus");
            this.labelAdapterStatus.Name = "labelAdapterStatus";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // comboBoxAdapters
            // 
            resources.ApplyResources(this.comboBoxAdapters, "comboBoxAdapters");
            this.comboBoxAdapters.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxAdapters.FormattingEnabled = true;
            this.comboBoxAdapters.Name = "comboBoxAdapters";
            this.comboBoxAdapters.SelectedIndexChanged += new System.EventHandler(this.comboBoxAdapters_SelectedIndexChanged);
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.helpToolStripMenuItem});
            resources.ApplyResources(this.menuStrip1, "menuStrip1");
            this.menuStrip1.Name = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.refreshIPInformationToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            resources.ApplyResources(this.fileToolStripMenuItem, "fileToolStripMenuItem");
            // 
            // refreshIPInformationToolStripMenuItem
            // 
            this.refreshIPInformationToolStripMenuItem.Name = "refreshIPInformationToolStripMenuItem";
            resources.ApplyResources(this.refreshIPInformationToolStripMenuItem, "refreshIPInformationToolStripMenuItem");
            this.refreshIPInformationToolStripMenuItem.Click += new System.EventHandler(this.refreshIPInformationToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.settingsToolStripMenuItem,
            this.toolStripSeparator1,
            this.copyInternalIPAddressToolStripMenuItem,
            this.copyExternalIPAddressToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            resources.ApplyResources(this.editToolStripMenuItem, "editToolStripMenuItem");
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            resources.ApplyResources(this.settingsToolStripMenuItem, "settingsToolStripMenuItem");
            this.settingsToolStripMenuItem.Click += new System.EventHandler(this.settingsToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            // 
            // copyInternalIPAddressToolStripMenuItem
            // 
            this.copyInternalIPAddressToolStripMenuItem.Name = "copyInternalIPAddressToolStripMenuItem";
            resources.ApplyResources(this.copyInternalIPAddressToolStripMenuItem, "copyInternalIPAddressToolStripMenuItem");
            // 
            // copyExternalIPAddressToolStripMenuItem
            // 
            this.copyExternalIPAddressToolStripMenuItem.Name = "copyExternalIPAddressToolStripMenuItem";
            resources.ApplyResources(this.copyExternalIPAddressToolStripMenuItem, "copyExternalIPAddressToolStripMenuItem");
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            resources.ApplyResources(this.helpToolStripMenuItem, "helpToolStripMenuItem");
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            resources.ApplyResources(this.aboutToolStripMenuItem, "aboutToolStripMenuItem");
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // statusStrip1
            // 
            resources.ApplyResources(this.statusStrip1, "statusStrip1");
            this.statusStrip1.Name = "statusStrip1";
            // 
            // notifyIcon1
            // 
            resources.ApplyResources(this.notifyIcon1, "notifyIcon1");
            this.notifyIcon1.ContextMenuStrip = this.contextMenuStrip1;
            this.notifyIcon1.DoubleClick += new System.EventHandler(this.notifyIcon1_DoubleClick);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolStripSeparator3,
            this.settingsToolStripMenuItem1,
            this.toolStripSeparator2,
            this.toolStripMenuItem2});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            resources.ApplyResources(this.contextMenuStrip1, "contextMenuStrip1");
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            resources.ApplyResources(this.toolStripMenuItem1, "toolStripMenuItem1");
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            resources.ApplyResources(this.toolStripMenuItem2, "toolStripMenuItem2");
            this.toolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItem2_Click);
            // 
            // settingsToolStripMenuItem1
            // 
            this.settingsToolStripMenuItem1.Name = "settingsToolStripMenuItem1";
            resources.ApplyResources(this.settingsToolStripMenuItem1, "settingsToolStripMenuItem1");
            this.settingsToolStripMenuItem1.Click += new System.EventHandler(this.settingsToolStripMenuItem1_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            resources.ApplyResources(this.toolStripSeparator2, "toolStripSeparator2");
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            resources.ApplyResources(this.toolStripSeparator3, "toolStripSeparator3");
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label labelExternalAddress;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBoxAdapters;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem copyInternalIPAddressToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copyExternalIPAddressToolStripMenuItem;
        private System.Windows.Forms.Label labelAdapterStatus;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label labelMacAddress;
        private System.Windows.Forms.Label labelSpeed;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label labelHostName;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ToolStripMenuItem refreshIPInformationToolStripMenuItem;
        private System.Windows.Forms.Label labelInternalAddress;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
    }
}

