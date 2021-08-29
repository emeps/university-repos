/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automovel;

/**
 *
 * @author emeps
 */
public class Automovel {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Carreta
        CargoCart carreta = new CargoCart();

        carreta.setCarModel("DW-720");
        carreta.setCarColor("Vermelha");
        carreta.setCarYear(2017);
        carreta.setCarBrand("DARF");
        carreta.setCarChassi("FF470A89BR098IT");
        carreta.setCarOwner("Fulano de Tal");
        carreta.setMaximumSpeed(140);
        carreta.setNumberMarchSpeed(16);
        carreta.setTankCapacity(190.0f);
        carreta.setDirection("Parado");

        carreta.setPesoLiquido(3.25f);
        carreta.setPesoMaximoCarga(50.6f);
        carreta.setTipoDeCarga("Combustível Liquído");
        carreta.setCodigoANTT("AN78KD90009TT");
        carreta.setNumeroDeEixos(6);
        carreta.vehicleInformation();
        carreta.carregarCarga(47.35f);


        carreta.vehicleInformationState();
        carreta.direcaoTrajetoRealizado();

    }
    
}
