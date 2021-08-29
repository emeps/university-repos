/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula4;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Complexo {
    private float a_real;
    private float b_imaginaria;

    public Complexo(){
        this.a_real = 0.00f;
        this.b_imaginaria = 0.00f;
    }
    public Complexo(float k, float m){
        this.a_real = k;
        this.b_imaginaria = m;
    }

    public Complexo soma(Complexo x, Complexo y){
        Complexo adicao = new Complexo();
        adicao.a_real = x.a_real + y.a_real;
        adicao.b_imaginaria = x.b_imaginaria + y.b_imaginaria;
        return adicao;
    }

    public Complexo subtracao(Complexo x, Complexo y){
        Complexo subtrai = new Complexo();
        subtrai.a_real = x.a_real - y.a_real;
        subtrai.b_imaginaria = x.b_imaginaria - y.b_imaginaria;
        return subtrai;
    }

    public Complexo multiplicacao(Complexo x, Complexo y){
        Complexo multiplica = new Complexo();
        //(ac - bd)
        multiplica.a_real = x.a_real*y.a_real - x.b_imaginaria*y.b_imaginaria;
        //(ad + bc)
        multiplica.b_imaginaria = x.a_real*y.b_imaginaria + x.b_imaginaria * y.a_real;
        return multiplica;
    }

    public void imprimeComplexo(Complexo x, String modificador){
        JOptionPane.showMessageDialog(null,"Numero Complexo: ("+ String.valueOf(x.a_real)+ modificador + String.valueOf(x.b_imaginaria)+"i)");
    }
    
}
