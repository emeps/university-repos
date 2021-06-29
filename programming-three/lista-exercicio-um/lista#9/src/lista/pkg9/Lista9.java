/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg9;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista9 {

    /**
     * @param args the command line arguments
     */
    public static float descontaConta(float valorTotalPagar){
        return (float) (valorTotalPagar - (valorTotalPagar*0.15));
    }
    public static float calculadoraQuilowatts(float valorTotalPagar, float quilowattsGasto){
        return (valorTotalPagar/quilowattsGasto);
    }
    public static float calcutadoraGastosTotal(float salarioMinimo, float quilowattsGasto){
        float valorTotalPagar = (salarioMinimo*quilowattsGasto)/800;
        return valorTotalPagar;
    }

    public static float salarioInput(){
        
        float salarioMinimo = Float.parseFloat(JOptionPane.showInputDialog(null, "Valor do salario minimo", "Salário Minímo"));
        return salarioMinimo;
    }

    public static float quilowattInput(){
        
        float quilowattsGasto = Float.parseFloat(JOptionPane.showInputDialog(null, "Valor do quilowatts gasto", "Quilowatt"));
        return quilowattsGasto;
    }

    public static void main(String[] args) {
        // TODO code application logic here
        float salarioMinimo = salarioInput();
        float quilowattsGasto = quilowattInput();
        float valorTotalPagar = calcutadoraGastosTotal(salarioMinimo, quilowattsGasto);
        float valorPorQuilowatt = calculadoraQuilowatts(valorTotalPagar, quilowattsGasto);
        float valorDescontado = descontaConta(valorTotalPagar);

        JOptionPane.showMessageDialog(null, "Valor total a pagar é: R$ " + valorTotalPagar +"  reais. \nValor por quilowatt é: R$ " + valorPorQuilowatt +" real/quilowatt. \nValor total a pagar com desconto 15% é: R$ " + valorDescontado +" reais. \n");
    }
    
}
