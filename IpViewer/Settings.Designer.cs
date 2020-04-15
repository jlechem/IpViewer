namespace IpViewer2
{
    partial class Settings
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
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Topmost");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Start Minimized");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Close To Tray");
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Minimize To Tray");
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Log External IP Address");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("IP Address");
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("Operational Status");
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Log Adapter Information", new System.Windows.Forms.TreeNode[] {
            treeNode6,
            treeNode7});
            System.Windows.Forms.TreeNode treeNode9 = new System.Windows.Forms.TreeNode("Enable Logging", new System.Windows.Forms.TreeNode[] {
            treeNode5,
            treeNode8});
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCANCEL = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.treeViewSettings = new System.Windows.Forms.TreeView();
            this.numericUpDownInterval = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownInterval)).BeginInit();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonOK
            // 
            this.buttonOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonOK.Location = new System.Drawing.Point(101, 9);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(75, 23);
            this.buttonOK.TabIndex = 0;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCANCEL
            // 
            this.buttonCANCEL.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonCANCEL.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCANCEL.Location = new System.Drawing.Point(182, 9);
            this.buttonCANCEL.Name = "buttonCANCEL";
            this.buttonCANCEL.Size = new System.Drawing.Size(75, 23);
            this.buttonCANCEL.TabIndex = 1;
            this.buttonCANCEL.Text = "CANCEL";
            this.buttonCANCEL.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.buttonOK);
            this.panel1.Controls.Add(this.buttonCANCEL);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 290);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(269, 44);
            this.panel1.TabIndex = 3;
            // 
            // treeViewSettings
            // 
            this.treeViewSettings.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.treeViewSettings.CheckBoxes = true;
            this.treeViewSettings.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewSettings.Location = new System.Drawing.Point(0, 38);
            this.treeViewSettings.Name = "treeViewSettings";
            treeNode1.Name = "TopMost";
            treeNode1.Tag = "Topmost";
            treeNode1.Text = "Topmost";
            treeNode2.Name = "StartMinimized";
            treeNode2.Tag = "StartMinimized";
            treeNode2.Text = "Start Minimized";
            treeNode3.Name = "CloseToTray";
            treeNode3.Tag = "CloseToTray";
            treeNode3.Text = "Close To Tray";
            treeNode4.Name = "MinimizeToTray";
            treeNode4.Tag = "MinimizeToTray";
            treeNode4.Text = "Minimize To Tray";
            treeNode5.Name = "LogExternalAddress";
            treeNode5.Tag = "LogExternalAddress";
            treeNode5.Text = "Log External IP Address";
            treeNode6.Name = "IPAddress";
            treeNode6.Tag = "IPAddress";
            treeNode6.Text = "IP Address";
            treeNode7.Name = "OperationalStatus";
            treeNode7.Tag = "OperationalStatus";
            treeNode7.Text = "Operational Status";
            treeNode8.Name = "LogAdapterInformation";
            treeNode8.Tag = "LogAdapterInformation";
            treeNode8.Text = "Log Adapter Information";
            treeNode9.Name = "EnableLogging";
            treeNode9.Tag = "EnableLogging";
            treeNode9.Text = "Enable Logging";
            this.treeViewSettings.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3,
            treeNode4,
            treeNode9});
            this.treeViewSettings.Size = new System.Drawing.Size(269, 252);
            this.treeViewSettings.TabIndex = 2;
            // 
            // numericUpDownInterval
            // 
            this.numericUpDownInterval.Location = new System.Drawing.Point(136, 7);
            this.numericUpDownInterval.Maximum = new decimal(new int[] {
            1440,
            0,
            0,
            0});
            this.numericUpDownInterval.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownInterval.Name = "numericUpDownInterval";
            this.numericUpDownInterval.Size = new System.Drawing.Size(120, 20);
            this.numericUpDownInterval.TabIndex = 13;
            this.numericUpDownInterval.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(118, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "Refresh Rate (minutes):";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.numericUpDownInterval);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(269, 38);
            this.panel2.TabIndex = 14;
            // 
            // Settings
            // 
            this.AcceptButton = this.buttonOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.buttonCANCEL;
            this.ClientSize = new System.Drawing.Size(269, 334);
            this.Controls.Add(this.treeViewSettings);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Settings";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "Ip Viewer Settings";
            this.TopMost = true;
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownInterval)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonOK;
        private System.Windows.Forms.Button buttonCANCEL;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TreeView treeViewSettings;
        private System.Windows.Forms.NumericUpDown numericUpDownInterval;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
    }
}