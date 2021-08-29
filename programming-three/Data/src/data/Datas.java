/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package data;

/**
 *
 * @author emeps
 */
public class Datas {
    private int dia, mes, ano; 
   
   public void alteraData(int d){
     this.dia = d;
   }
   
   public void alteraData(int d, int m){
     this.dia = d;
     this.mes = m;
   }
   
   public void alteraData(int d, int m, int a){
     this.dia = d;
     this.mes = m;
     this.ano = a;
   }
   
   public void imprime(){
     System.out.println("Dia: "+this.dia+ " ;Mês: "+this.mes+" ;Ano: "+this.ano);
   }
    
   
}
