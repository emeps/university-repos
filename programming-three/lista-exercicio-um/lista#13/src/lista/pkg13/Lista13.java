/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg13;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista13 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String sequencia = "0";
        int numerosQuadrados = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um numero"));
        while(numerosQuadrados != 0){
            sequencia += " " + String.valueOf((numerosQuadrados*numerosQuadrados));
            numerosQuadrados = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um numero"));
        }
        JOptionPane.showMessageDialog(null, sequencia);
        
    }
    
}
