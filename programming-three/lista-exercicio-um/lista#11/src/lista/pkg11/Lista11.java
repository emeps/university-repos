/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg11;


import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista11 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        int valor = 0;
        int x = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um numero"));

        for (int j = 1; j < x; j++) {

            if (x % j == 0)
                valor += j;

        }
        if (valor == x)
            JOptionPane.showMessageDialog(null, x + " é um numero perfeito");
        else
            JOptionPane.showMessageDialog(null, x + " não é numero perfeito");
    }

}
