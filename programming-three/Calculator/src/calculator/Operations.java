/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Operations {
    private int position;
    private double fValue;
    private double sValue;

    public void Operations() {
        this.fValue = 0.0;
        this.sValue = 0.0;
        
    }
    public Double stringTreatmentOperations(String valueDisplay, String signal){
        String[] fSValue = new String[2]; 
        switch (signal) {
            case "plus":
                fSValue = valueDisplay.split("\\+");
                this.fValue = Double.parseDouble(fSValue[0]);
                this.sValue = Double.parseDouble(fSValue[1]);
                return plusOperation();
            case "minus":
                position = valueDisplay.indexOf("-",  2);
                this.fValue = Double.parseDouble(valueDisplay.substring(0, position));
                this.sValue = Double.parseDouble(valueDisplay.substring(position+1, valueDisplay.length()));
                return minusOperation();
            case "times":
                fSValue = valueDisplay.split("*");
                this.fValue = Double.parseDouble(fSValue[0]);
                this.sValue = Double.parseDouble(fSValue[1]);
                return timesOperation();
            case "dividedBy":
                fSValue = valueDisplay.split("/");
                this.fValue = Double.parseDouble(fSValue[0]);
                this.sValue = Double.parseDouble(fSValue[1]);
                return dividedByOperation();
            case "sqrtTo":
                this.fValue = Double.parseDouble(valueDisplay);
                return sqrtToOperation();
            case "logarithm":
                this.fValue = Double.parseDouble(valueDisplay);
                return logarithmOperation();
        }
        return null;
        
    }
    
    private double plusOperation() {
        return (double)(this.fValue + this.sValue);
    }

    private double minusOperation() {
        return (double)(this.fValue - this.sValue);
    }

    private double timesOperation() {
        return (double)(this.fValue * this.sValue);
    }

    private Double dividedByOperation()  {
        try {
            if(this.sValue <=0)
                throw new ArithmeticException();
            else
                return (double)(this.fValue / this.sValue);
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Divisão impossível!\nDivisão por zero.");
            return 0.0;
        }
    }

    private Double sqrtToOperation(){
        try {
            if(this.fValue < 0)
                throw new ArithmeticException();
            else    
                return (Math.sqrt(this.fValue));
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Raiz impossível!\nRaiz de valor negativo.");
            return 0.0;
        }
    }

    private Double logarithmOperation() {
        try {
            if(this.fValue <= 0)
                throw new ArithmeticException();
            else    
                return (Math.log(this.fValue));
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Logaritmo impossível!\nLogaritmo menor que zero.");
            return 0.0;
        }
    }

}
