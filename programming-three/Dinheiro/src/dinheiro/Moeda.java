/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dinheiro;

import java.math.BigDecimal;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Moeda {
    private int reais;
    private double centavos;
    private String valor;
    private enum decimal{Um, Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove};
    private enum dezena {Dez, Vinte, Trinta, Quarenta, Cinquenta, Sessenta, Setenta, Oitenta, Noventa};
    private enum centena {Cem,Cento, Duzentos, Trezentos, Quatrocentos, Quinhentos, Seiscentos, Setecentos, Oitocentos, Novecentos, Mil};

    //Constructor

    public Moeda(){
        this.reais = 0;
        this.centavos = 0;
        this.valor = "";
    }
    // Recebo a String
    public void definirValor(double valor){
        if(validaDinheito((int)valor, (valor - this.reais))){
            this.reais = (int)valor;
            this.centavos = (valor - this.reais);
            this.centavos = Math.round((this.centavos*100.00))/100.00;
            this.valor = String.valueOf(this.reais+this.centavos);
        }else{
            System.out.println("Valor não valído");
        }
    }

    public String obterValor(){
        return this.valor;
    }

    private String valorPorExtenso(){
        int centena1 = (int)Math.abs((this.reais / 100)); 
        int dezena1 = (int)Math.abs((this.reais % 100) / 10);
        int unidade = (int)Math.abs((this.reais % 100) % 10);
        int centavosDezena =(int)Math.abs(((this.centavos*100) % 100) / 10);
        int centavosDezena2 =(int)Math.abs(((this.centavos*100) % 100) % 10);

        String strCentena = "";
        String strDezena = "";
        String strUnidade = "";
        String strCentavosDezena ="";
        String strCentavosUnidade = "";
        String valorExtenso = "";

        if(centena1 != 0){
            if(dezena1 == 0 && unidade ==0)
                strCentena = String.valueOf(centena.values()[centena1-1]);
            else  
              strCentena = String.valueOf(centena.values()[centena1]) + " e ";
        }else{
            strCentena = "";
        }
        if(dezena1 != 0){
            if(centena1 == 0 && unidade ==0)
                strDezena = String.valueOf(dezena.values()[dezena1-1]);
            else  
                strDezena = String.valueOf(dezena.values()[dezena1 - 1])+ " e ";
        }else{
            strDezena = "";
        }
        if(unidade != 0){
            strUnidade = String.valueOf(decimal.values()[unidade - 1]);
        }else{
            strUnidade = "";
        }
        if(centavosDezena != 0){
            strCentavosDezena = String.valueOf(dezena.values()[centavosDezena - 1]);
        }
        if(centavosDezena2 != 0){
            strCentavosUnidade = String.valueOf(decimal.values()[centavosDezena2 - 1]);
        }
        if(centena1 == 0 && dezena1 == 0 && unidade == 0){
            if(centavosDezena == 0)
                valorExtenso = strCentavosUnidade + " Centavos";
            if(centavosDezena2 == 0)
                valorExtenso = strCentavosDezena  + " Centavos";
            if(centavosDezena == 0 && centavosDezena2 == 0)
                valorExtenso = "";
            else
                return strCentavosDezena +" e "+ strCentavosUnidade + " Centavos";
        }
        if(centavosDezena == 0 && centavosDezena2 == 0)
            valorExtenso = strCentena + strDezena + strUnidade +" Reais";
        else
            valorExtenso = strCentena + strDezena + strUnidade +" Reais e "+ strCentavosDezena +" "+ strCentavosUnidade + " Centavos";
        return valorExtenso;

    }

    public void imprimirValor(){
        System.out.println("R$"+obterValor()+" reais");
    }
    
    public void imprimirValorPorExtenso(){

        System.out.println("--------------------------------");
        System.out.println(valorPorExtenso());
        System.out.println("--------------------------------");
    }

    private boolean validaDinheito(int reais, double centavos){
        if(reais < 1000 && reais > -1000){
            return true;
        }else{
            if(reais == 1000 || reais == -1000){
                if(centavos > 0.00 || centavos < 0.00){
                    return false;
                }else{
                    return true;
                }
            }else{
                return false;
            }
        }
    }
 }
