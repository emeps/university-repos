package automovel;

import javax.swing.*;

public class FeaturesCar {
    private String carModel;
    private String carColor;
    private int carYear;
    private String carBrand;
    private String carChassi;
    private String carOwner;
    private int maximumSpeed;
    private int numberMarchSpeed;
    private float tankCapacity;
    private String direction;
    private int currentSpeed;
    private int currentMarchSpeed;
    private int fuelVolume;

    public FeaturesCar() {
        this.carModel = "";
        this.carColor = "";
        this.carYear = 0;
        this.carBrand = "";
        this.carChassi = "";
        this.carOwner = "";
        this.maximumSpeed = 0;
        this.numberMarchSpeed = 0;
        this.tankCapacity = 0;
        this.direction = "stand by";
        this.currentSpeed = 0;
        this.currentMarchSpeed = 0;
        this.fuelVolume = 0;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public void setCarColor(String carColor) {
        this.carColor = carColor;
    }

    public void setCarYear(int carYear) {
        this.carYear = carYear;
    }

    public void setCarBrand(String carBrand) {
        this.carBrand = carBrand;
    }

    public void setCarChassi(String carChassi) {
        this.carChassi = carChassi;
    }

    public void setCarOwner(String carOwner) {
        this.carOwner = carOwner;
    }

    public void setMaximumSpeed(int maximumSpeed) {
        this.maximumSpeed = maximumSpeed;
    }

    public void setNumberMarchSpeed(int numberMarchSpeed) {
        this.numberMarchSpeed = numberMarchSpeed;
    }

    public void setTankCapacity(float tankCapacity) {
        this.tankCapacity = tankCapacity;
    }

    public void setDirection(String direction) {
        this.direction = direction;
    }

    public void setCurrentSpeed(int currentSpeed) {
        this.currentSpeed = currentSpeed;
    }

    public void setCurrentMarchSpeed(int currentMarchSpeed) {
        this.currentMarchSpeed = currentMarchSpeed;
    }

    public void setFuelVolume(int fuelVolume) {
        this.fuelVolume = fuelVolume;
    }

    public void aumentarVelocidade() {
        if (this.currentSpeed >= this.maximumSpeed)
            this.currentSpeed = this.maximumSpeed;
        else
            this.currentSpeed += 5;
    }
    public void diminuirVelocidade() {
        if (this.currentSpeed <= 0)
            this.currentSpeed = 0;
        else
            this.currentSpeed -= 4;
    }
    public void setTrajeto(String trajetoCircuito) {
        this.direction = trajetoCircuito;
    }
    public void setDirigir(int velocidade, String direcao) {
        setTrajeto(direcao);
        if (direcao != "reta"){
            while (this.currentSpeed >= velocidade){
                diminuirVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
            if(this.currentSpeed <= 0){
                diminuirVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
        }
        else
            while (this.currentSpeed <= velocidade){
                aumentarVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
        if(this.currentSpeed < velocidade){
            aumentarVelocidade();
            trocaAutomaticaMarcha(velocidade);
        }

    }
    private void trocaAutomaticaMarcha(int velocidade){
        if(velocidade <=0 )
            this.currentMarchSpeed = 0;
        if(velocidade >0 && velocidade < 7)
            trocaDeMarcha(1);
        if(velocidade >=7 && velocidade < 17)
            trocaDeMarcha(2);
        if(velocidade >=17 && velocidade < 40)
            trocaDeMarcha(3);
        if(velocidade >=40 && velocidade < 80)
            trocaDeMarcha(4);
        if(velocidade >=80 && velocidade < 130)
            trocaDeMarcha(5);
        if(velocidade >=130)
            trocaDeMarcha(this.numberMarchSpeed);
    }

    public void direcaoTrajetoRealizado(){
        System.out.println("-----------------------------------------------");
        System.out.println("Direção: " + this.direction);
        System.out.println("Velocidade: " + this.currentSpeed+"km/h");
        System.out.println("Marcha Atual: " + this.currentMarchSpeed);
        System.out.println("-----------------------------------------------");
    }
    public void trocaDeMarcha(int novaMarcha) {
        if (novaMarcha >= 1 && novaMarcha <= 6) {
            int diferencaMarcha = Math.abs((this.currentMarchSpeed + 1 ) - novaMarcha);
            if (diferencaMarcha <= 2 && diferencaMarcha >= 0) {
                if (this.direction == "reta") {
                    while(this.currentMarchSpeed != novaMarcha)
                        this.currentMarchSpeed += 1;
                }else{
                    while(this.currentMarchSpeed != novaMarcha)
                        this.currentMarchSpeed -=1;
                }
            } else
                JOptionPane.showMessageDialog(null, "Impossivel realizar a troca de marcha");
        } else
            JOptionPane.showMessageDialog(null, "Sistema de marchas incorretas.");
    }
    public void autonomiaDoCarro(float consumoMedio){
        System.out.println("Autonomia do veiculo é de: " + (this.fuelVolume*consumoMedio) + "km");
        System.out.println("Consumo Médio é de: " + consumoMedio + "km/L");
        verificarQuantidadeDeCombustivel();
    }
    public void verificarQuantidadeDeCombustivel(){
        System.out.println("Capacidade Máxima de Combustível: " + this.tankCapacity + " litros\n"+
                "Volume Atual de Combustível: " +this.fuelVolume + " litros");
    }

    public void vehicleInformation(){
        System.out.println("-----------------------------------------------");
        System.out.println("Informações do veículo");
        System.out.println("Modelo: "+this.carModel);
        System.out.println("Cor: "+this.carColor);
        System.out.println("Ano: "+this.carYear);
        System.out.println("Fabricante: "+this.carBrand);
        System.out.println("Chassi: "+this.carChassi);
        System.out.println("Proprietário: "+this.carOwner);
        System.out.println("Velocidade Máxima: "+this.maximumSpeed+"km/h");
        System.out.println("Número de Marchas: "+this.numberMarchSpeed);
        System.out.println("Capacidade do tanque: "+this.tankCapacity+"L");
        System.out.println("-----------------------------------------------");
    }
    public void vehicleInformationState(){
        System.out.println("-----------------------------------------------");
        System.out.println("Informações do Estado Atual do Veículo");
        System.out.println("Velocidade Atual: "+this.currentSpeed);
        System.out.println("Marcha Atual Atual: "+this.currentMarchSpeed);
        verificarQuantidadeDeCombustivel();
        System.out.println("-----------------------------------------------");
    }
}
