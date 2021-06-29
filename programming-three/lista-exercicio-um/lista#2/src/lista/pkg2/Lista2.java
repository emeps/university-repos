/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg2;

import java.util.Scanner;
import javax.swing.JOptionPane;
/**
 *
 * @author emeps
 */
public class Lista2 {
    public static Boolean verificaTriangulo(int ld1, int ld2, int ld3){
        return !(ld1 == 0 || ld2 == 0 || ld3 == 0);
    }
    public static String classificadorTriangulo(int ld1, int ld2, int ld3){
        if (ld1 != ld2 && ld1!=ld3 && ld2!= ld3)
            return ("Triângulo Escaleno");
        if (ld1 == ld2 && ld2 == ld3 && ld3 == ld1 )
            return ("Triângulo Equilatero");
        else
            return ("Triângulo Isóceles");
    }
    public static void main(String[] args){
        boolean verificado = false;
        int entrada = 0;
        int ld1, ld2, ld3;
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Insira os valores dos lados do triângulo.");

        ld1 = Integer.parseInt(JOptionPane.showInputDialog("Entre com valor do lado do triângulo."));
        ld2 = Integer.parseInt(JOptionPane.showInputDialog("Entre com valor do lado do triângulo."));
        ld3 = Integer.parseInt(JOptionPane.showInputDialog("Entre com valor do lado do triângulo."));
        verificado = verificaTriangulo(ld1, ld2, ld3);
        if(verificado)
            JOptionPane.showMessageDialog(null,classificadorTriangulo(ld1,ld2,ld3),"Triângulo",JOptionPane.INFORMATION_MESSAGE);
        else
            JOptionPane.showMessageDialog(null,"Os valores dados não formam um triângulo.", "Alert",JOptionPane.INFORMATION_MESSAGE);
    }
    
}
