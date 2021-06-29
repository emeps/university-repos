/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg12;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista12 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int contador = 0;
        int produto = 0;
        boolean verificadoTriangular; 
        int valorAnalisado = Integer.parseInt(JOptionPane.showInputDialog("Entre com valor para ser analisado:"));

        produto = 0;
        verificadoTriangular = false;
        contador = 0;

        while ((contador <= 10) && (verificadoTriangular == false)) {
            produto = contador * (contador + 1) * (contador + 2);
            if (produto == valorAnalisado)
                verificadoTriangular = true;
            else
                contador++;
        }

        if (verificadoTriangular == true)
            JOptionPane.showMessageDialog(null," O valor informado é triangular. \n"+ valorAnalisado +" = "+ contador + " * " + (contador + 1) + " * " +(contador + 2));
        else
            JOptionPane.showMessageDialog(null, valorAnalisado +" não é triangular");
    
    }
}
