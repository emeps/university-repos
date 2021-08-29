/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dinheiro;

/**
 *
 * @author emeps
 */
public class Dinheiro {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Moeda moeda = new Moeda();

        
        moeda.definirValor(-103.40);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(-10.45);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(0.45);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(0.32);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(100.00);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(10.00);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(998.45);
        moeda.imprimirValorPorExtenso();
        moeda.definirValor(555.65);
        moeda.imprimirValorPorExtenso();
        System.out.println("------------------------------------------------");
        moeda.imprimirValor();

        
    }
    
}
