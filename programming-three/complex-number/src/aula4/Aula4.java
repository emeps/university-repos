/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4;

/**
 *
 * @author emeps
 */

public class Aula4 {


    public static void main(String[] args) {
        Complexo X = new Complexo(12,4);
        Complexo Y = new Complexo(9,4);
        Complexo Z = new Complexo();
        //Soma 
        Z = Z.soma(X, Y);
        Z.imprimeComplexo(Z, " , ");

        //Subtração
        Z = Z.subtracao(X, Y);
        Z.imprimeComplexo(Z, " , ");

        //Multiplicação
        Z = Z.multiplicacao(X, Y);
        Z.imprimeComplexo(Z, " + ");

    }
    
}
