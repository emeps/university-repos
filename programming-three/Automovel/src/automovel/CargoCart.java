package automovel;

public class CargoCart extends FeaturesCar {
    private float pesoBruto;
    private float pesoLiquido;
    private float pesoMaximoCarga;
    private float pesoDaCarga;
    private String tipoDeCarga;
    private String codigoANTT;
    private int numeroDeEixos;

    public CargoCart() {
        this.pesoBruto = 0.0f;
        this.pesoLiquido = 0.0f;
        this.pesoMaximoCarga = 0.0f;
        this.pesoDaCarga = 0.0f;
        this.tipoDeCarga = "";
        this.codigoANTT = "";
        this.numeroDeEixos = 0;
    }


    public void setPesoLiquido(float pesoLiquido) {
        this.pesoLiquido = pesoLiquido;
    }

    public void setPesoMaximoCarga(float pesoMaximoCarga) {
        this.pesoMaximoCarga = pesoMaximoCarga;
    }

    public void setTipoDeCarga(String tipoDeCarga) {
        this.tipoDeCarga = tipoDeCarga;
    }

    public void setCodigoANTT(String codigoANTT) {
        this.codigoANTT = codigoANTT;
    }

    public void setNumeroDeEixos(int numeroDeEixos) {
        this.numeroDeEixos = numeroDeEixos;
    }


    public  void carregarCarga(float pesoCarga){
        System.out.println("-----------------------------------------------");
        System.out.println("Carregando Carga");
        if ((pesoCarga + this.pesoLiquido) < this.pesoMaximoCarga) {
            System.out.println("Carga carregada. Boa Viagem!");
            this.pesoDaCarga = pesoCarga;
            this.pesoBruto = this.pesoDaCarga+this.pesoLiquido;
        }
        else{
            System.out.println("Peso excedido!");
            this.pesoBruto = this.pesoDaCarga+this.pesoLiquido;
        }
        System.out.println("-----------------------------------------------");
        vehicleInformationCargo();
    }
    private void vehicleInformationCargo(){
        System.out.println("-----------------------------------------------");
        System.out.println("Informações da Carga");
        System.out.println("Peso Bruto: "+this.pesoBruto+" Toneladas");
        System.out.println("Peso Liquido: "+this.pesoLiquido+" Toneladas");
        System.out.println("Peso Maximo de Carga: "+this.pesoMaximoCarga+" Toneladas");
        System.out.println("Peso de Carga Atual: "+this.pesoDaCarga+" Toneladas");
        System.out.println("Tipo de Carga: "+this.tipoDeCarga);
        System.out.println("Código ANTT: "+this.codigoANTT);
        System.out.println("Numero de eixos: "+this.numeroDeEixos);
        System.out.println("-----------------------------------------------");
    }
}
