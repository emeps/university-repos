/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telefone;

/**
 *
 * @author emeps
 */
public class Celular {
     private static int total=0;
   private int serial;
   
   public Celular (int s){
       this.serial = s;
       Celular.total=Celular.total+1;
   }
   
   public int getSerial(){
       return this.serial;
   }
   
    public static int getTotal(){
       return Celular.total;
   }
}
