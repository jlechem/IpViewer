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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            groupBox1 = new System.Windows.Forms.GroupBox();
            labelHostName = new System.Windows.Forms.Label();
            label9 = new System.Windows.Forms.Label();
            labelExternalAddress = new System.Windows.Forms.Label();
            label2 = new System.Windows.Forms.Label();
            groupBox2 = new System.Windows.Forms.GroupBox();
            labelInternalAddress = new System.Windows.Forms.Label();
            label5 = new System.Windows.Forms.Label();
            labelSpeed = new System.Windows.Forms.Label();
            label7 = new System.Windows.Forms.Label();
            labelMacAddress = new System.Windows.Forms.Label();
            label6 = new System.Windows.Forms.Label();
            labelAdapterStatus = new System.Windows.Forms.Label();
            label4 = new System.Windows.Forms.Label();
            comboBoxAdapters = new System.Windows.Forms.ComboBox();
            label3 = new System.Windows.Forms.Label();
            menuStrip1 = new System.Windows.Forms.MenuStrip();
            fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            refreshIPInformationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            viewPacketsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            copyInternalIPAddressToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            copyExternalIPAddressToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            statusStrip1 = new System.Windows.Forms.StatusStrip();
            toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            notifyIcon1 = new System.Windows.Forms.NotifyIcon(components);
            contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(components);
            toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            settingsToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            copyExternalAddressToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            timer1 = new System.Windows.Forms.Timer(components);
            timer2 = new System.Windows.Forms.Timer(components);
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            menuStrip1.SuspendLayout();
            statusStrip1.SuspendLayout();
            contextMenuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(labelHostName);
            groupBox1.Controls.Add(label9);
            groupBox1.Controls.Add(labelExternalAddress);
            groupBox1.Controls.Add(label2);
            resources.ApplyResources(groupBox1, "groupBox1");
            groupBox1.Name = "groupBox1";
            groupBox1.TabStop = false;
            // 
            // labelHostName
            // 
            resources.ApplyResources(labelHostName, "labelHostName");
            labelHostName.Name = "labelHostName";
            // 
            // label9
            // 
            resources.ApplyResources(label9, "label9");
            label9.Name = "label9";
            // 
            // labelExternalAddress
            // 
            resources.ApplyResources(labelExternalAddress, "labelExternalAddress");
            labelExternalAddress.Name = "labelExternalAddress";
            // 
            // label2
            // 
            resources.ApplyResources(label2, "label2");
            label2.Name = "label2";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(labelInternalAddress);
            groupBox2.Controls.Add(label5);
            groupBox2.Controls.Add(labelSpeed);
            groupBox2.Controls.Add(label7);
            groupBox2.Controls.Add(labelMacAddress);
            groupBox2.Controls.Add(label6);
            groupBox2.Controls.Add(labelAdapterStatus);
            groupBox2.Controls.Add(label4);
            groupBox2.Controls.Add(comboBoxAdapters);
            groupBox2.Controls.Add(label3);
            resources.ApplyResources(groupBox2, "groupBox2");
            groupBox2.Name = "groupBox2";
            groupBox2.TabStop = false;
            // 
            // labelInternalAddress
            // 
            resources.ApplyResources(labelInternalAddress, "labelInternalAddress");
            labelInternalAddress.Name = "labelInternalAddress";
            // 
            // label5
            // 
            resources.ApplyResources(label5, "label5");
            label5.Name = "label5";
            // 
            // labelSpeed
            // 
            resources.ApplyResources(labelSpeed, "labelSpeed");
            labelSpeed.Name = "labelSpeed";
            // 
            // label7
            // 
            resources.ApplyResources(label7, "label7");
            label7.Name = "label7";
            // 
            // labelMacAddress
            // 
            resources.ApplyResources(labelMacAddress, "labelMacAddress");
            labelMacAddress.Name = "labelMacAddress";
            // 
            // label6
            // 
            resources.ApplyResources(label6, "label6");
            label6.Name = "label6";
            // 
            // labelAdapterStatus
            // 
            resources.ApplyResources(labelAdapterStatus, "labelAdapterStatus");
            labelAdapterStatus.Name = "labelAdapterStatus";
            // 
            // label4
            // 
            resources.ApplyResources(label4, "label4");
            label4.Name = "label4";
            // 
            // comboBoxAdapters
            // 
            resources.ApplyResources(comboBoxAdapters, "comboBoxAdapters");
            comboBoxAdapters.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            comboBoxAdapters.FormattingEnabled = true;
            comboBoxAdapters.Name = "comboBoxAdapters";
            comboBoxAdapters.SelectedIndexChanged += comboBoxAdapters_SelectedIndexChanged;
            // 
            // label3
            // 
            resources.ApplyResources(label3, "label3");
            label3.Name = "label3";
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] { fileToolStripMenuItem, editToolStripMenuItem, helpToolStripMenuItem });
            resources.ApplyResources(menuStrip1, "menuStrip1");
            menuStrip1.Name = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] { refreshIPInformationToolStripMenuItem });
            fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            resources.ApplyResources(fileToolStripMenuItem, "fileToolStripMenuItem");
            // 
            // refreshIPInformationToolStripMenuItem
            // 
            refreshIPInformationToolStripMenuItem.Name = "refreshIPInformationToolStripMenuItem";
            resources.ApplyResources(refreshIPInformationToolStripMenuItem, "refreshIPInformationToolStripMenuItem");
            refreshIPInformationToolStripMenuItem.Click += refreshIPInformationToolStripMenuItem_Click;
            // 
            // editToolStripMenuItem
            // 
            editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] { settingsToolStripMenuItem, toolStripSeparator1, viewPacketsToolStripMenuItem, toolStripSeparator5, copyInternalIPAddressToolStripMenuItem, copyExternalIPAddressToolStripMenuItem });
            editToolStripMenuItem.Name = "editToolStripMenuItem";
            resources.ApplyResources(editToolStripMenuItem, "editToolStripMenuItem");
            // 
            // settingsToolStripMenuItem
            // 
            settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            resources.ApplyResources(settingsToolStripMenuItem, "settingsToolStripMenuItem");
            settingsToolStripMenuItem.Click += settingsToolStripMenuItem_Click;
            // 
            // toolStripSeparator1
            // 
            toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(toolStripSeparator1, "toolStripSeparator1");
            // 
            // viewPacketsToolStripMenuItem
            // 
            viewPacketsToolStripMenuItem.Name = "viewPacketsToolStripMenuItem";
            resources.ApplyResources(viewPacketsToolStripMenuItem, "viewPacketsToolStripMenuItem");
            // 
            // toolStripSeparator5
            // 
            toolStripSeparator5.Name = "toolStripSeparator5";
            resources.ApplyResources(toolStripSeparator5, "toolStripSeparator5");
            // 
            // copyInternalIPAddressToolStripMenuItem
            // 
            copyInternalIPAddressToolStripMenuItem.Name = "copyInternalIPAddressToolStripMenuItem";
            resources.ApplyResources(copyInternalIPAddressToolStripMenuItem, "copyInternalIPAddressToolStripMenuItem");
            copyInternalIPAddressToolStripMenuItem.Click += copyInternalIPAddressToolStripMenuItem_Click;
            // 
            // copyExternalIPAddressToolStripMenuItem
            // 
            copyExternalIPAddressToolStripMenuItem.Name = "copyExternalIPAddressToolStripMenuItem";
            resources.ApplyResources(copyExternalIPAddressToolStripMenuItem, "copyExternalIPAddressToolStripMenuItem");
            copyExternalIPAddressToolStripMenuItem.Click += copyExternalIPAddressToolStripMenuItem_Click;
            // 
            // helpToolStripMenuItem
            // 
            helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] { aboutToolStripMenuItem });
            helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            resources.ApplyResources(helpToolStripMenuItem, "helpToolStripMenuItem");
            // 
            // aboutToolStripMenuItem
            // 
            aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            resources.ApplyResources(aboutToolStripMenuItem, "aboutToolStripMenuItem");
            aboutToolStripMenuItem.Click += aboutToolStripMenuItem_Click;
            // 
            // statusStrip1
            // 
            statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] { toolStripStatusLabel1 });
            resources.ApplyResources(statusStrip1, "statusStrip1");
            statusStrip1.Name = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            resources.ApplyResources(toolStripStatusLabel1, "toolStripStatusLabel1");
            toolStripStatusLabel1.Spring = true;
            // 
            // notifyIcon1
            // 
            resources.ApplyResources(notifyIcon1, "notifyIcon1");
            notifyIcon1.ContextMenuStrip = contextMenuStrip1;
            notifyIcon1.DoubleClick += notifyIcon1_DoubleClick;
            // 
            // contextMenuStrip1
            // 
            contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] { toolStripMenuItem1, toolStripSeparator3, settingsToolStripMenuItem1, toolStripSeparator2, copyExternalAddressToolStripMenuItem, toolStripSeparator4, toolStripMenuItem2 });
            contextMenuStrip1.Name = "contextMenuStrip1";
            resources.ApplyResources(contextMenuStrip1, "contextMenuStrip1");
            // 
            // toolStripMenuItem1
            // 
            toolStripMenuItem1.Name = "toolStripMenuItem1";
            resources.ApplyResources(toolStripMenuItem1, "toolStripMenuItem1");
            toolStripMenuItem1.Click += toolStripMenuItem1_Click;
            // 
            // toolStripSeparator3
            // 
            toolStripSeparator3.Name = "toolStripSeparator3";
            resources.ApplyResources(toolStripSeparator3, "toolStripSeparator3");
            // 
            // settingsToolStripMenuItem1
            // 
            settingsToolStripMenuItem1.Name = "settingsToolStripMenuItem1";
            resources.ApplyResources(settingsToolStripMenuItem1, "settingsToolStripMenuItem1");
            settingsToolStripMenuItem1.Click += settingsToolStripMenuItem1_Click;
            // 
            // toolStripSeparator2
            // 
            toolStripSeparator2.Name = "toolStripSeparator2";
            resources.ApplyResources(toolStripSeparator2, "toolStripSeparator2");
            // 
            // copyExternalAddressToolStripMenuItem
            // 
            copyExternalAddressToolStripMenuItem.Name = "copyExternalAddressToolStripMenuItem";
            resources.ApplyResources(copyExternalAddressToolStripMenuItem, "copyExternalAddressToolStripMenuItem");
            copyExternalAddressToolStripMenuItem.Click += copyExternalAddressToolStripMenuItem_Click;
            // 
            // toolStripSeparator4
            // 
            toolStripSeparator4.Name = "toolStripSeparator4";
            resources.ApplyResources(toolStripSeparator4, "toolStripSeparator4");
            // 
            // toolStripMenuItem2
            // 
            toolStripMenuItem2.Name = "toolStripMenuItem2";
            resources.ApplyResources(toolStripMenuItem2, "toolStripMenuItem2");
            toolStripMenuItem2.Click += toolStripMenuItem2_Click;
            // 
            // timer1
            // 
            timer1.Enabled = true;
            timer1.Interval = 3600000;
            timer1.Tick += timer1_Tick;
            // 
            // timer2
            // 
            timer2.Enabled = true;
            timer2.Interval = 500;
            timer2.Tick += timer2_Tick;
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Controls.Add(statusStrip1);
            Controls.Add(menuStrip1);
            DoubleBuffered = true;
            FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            MaximizeBox = false;
            Name = "Form1";
            FormClosing += Form1_FormClosing;
            Load += Form1_Load;
            Resize += Form1_Resize;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            statusStrip1.ResumeLayout(false);
            statusStrip1.PerformLayout();
            contextMenuStrip1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
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
        private System.Windows.Forms.ToolStripMenuItem copyExternalAddressToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.ToolStripMenuItem viewPacketsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
    }
}

