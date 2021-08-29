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
public class Telefone {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Total: "+Celular.getTotal());
        Celular c = new Celular (123);
        Celular d = new Celular (456);      
        System.out.println("Total: "+Celular.getTotal());
        System.out.println("Serial: "+d.getSerial());
    }
    
}
