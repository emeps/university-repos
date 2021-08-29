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
public class Data {


    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Datas d = new Datas ();
        d.alteraData(31);
        d.imprime();
        d.alteraData(31, 12);
        d.imprime();
        d.alteraData(31, 12, 1969);
        d.imprime();
    }
    
}
