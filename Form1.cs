using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace brazoRobot
{
    public partial class Form1 : Form
    {
        System.IO.Ports.SerialPort Arduino;
        string rotarBaseIzquierda = "";
        string rotarBaseDerecha = "";
        string rotarHombroArriba = "";
        string rotarHombroAbajo = "";
        string rotarCodoArriba = "";
        string rotarCodoAbajo = "";
        string rotarManoAbrir = "";
        string rotarManoCerrar = "";
        public Form1()
        {
            InitializeComponent();
            abrirPuerto();
        }

        private void abrirPuerto()
        {
            Arduino = new System.IO.Ports.SerialPort();
            Arduino.PortName = "COM5";
            Arduino.BaudRate = 9600;
            Arduino.Open();
        }

        //rotar base a la izquierda
        private void RBi_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarBaseIzquierda);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarBaseDerecha);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarHombroArriba);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarHombroAbajo);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarCodoArriba);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarCodoAbajo);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarManoAbrir);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Arduino.WriteLine(rotarManoCerrar);
        }
    }
}
