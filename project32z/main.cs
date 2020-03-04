using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Data;
using Internal;
using System;

namespace HiddenPassword
{
    class Program
    {
        static void Main()
        {
            int t = 0, n = 0, pos = 0;
            string s = "";
            List <string> box = new List<string> ();
            t = Convert.toInt32(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                n = Convert.toInt32(Console.ReadLine());
                s = Console.ReadLine();
                pos = s.indexOf(" ");
                for (int j = 0; j < n; j++)
                {
                    box.Add(s.Substring());
                }
                foreach (string a in box)
                {
                    foreach (char c in a)
                    {
                        
                    }            
                }
                }
        }

        public static string ConvToBin(char c)
        {
            int temp = 0;
            string s = "";
            temp = c;
            s += temp.ToString();
            return s;
        }
    }
}