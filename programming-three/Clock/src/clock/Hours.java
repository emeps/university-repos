/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clock;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Hours {
    private int hours;
    private int minutes;
    private int seconds;

    private int hoursAlarm;
    private int minutesAlarm;

    public Hours() {
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
    }

    public void setHours(int hours, int minutes) {
        if (hours < 24 && minutes < 60) {
            this.hours = hours;
            this.minutes = minutes;
        } else {
            System.out.println("Dados Invalidos");
        }
    }

    public void setHours(int hours, int minutes, int seconds) {
        if (hours < 24 && minutes < 60 && seconds < 60) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        } else {
            System.out.println("Dados Invalidos");
        }
    }

    public void clockHours() throws InterruptedException {

        while (true) {
            this.seconds++;
            if (this.seconds == 60) {
                this.seconds = 0;
                this.minutes++;
            }
            if (this.minutes == 60) {
                this.seconds = 0;
                this.minutes = 0;
                this.hours++;
            }
            if (this.hours == 24) {
                this.seconds = 0;
                this.minutes = 0;
                this.hours = 0;
            }
            if (this.hoursAlarm != 0 && this.minutesAlarm != 0)
                clockAlarm();
            Thread.sleep(1000);
        }
    }

    public void displayHours() {
        System.out.println("HORA : MINUTO : SEGUNDO");
        System.out.println(this.hours + " : " + this.minutes + " : " + this.seconds);
        System.out.println("HORA : MINUTO - ALARME");
        System.out.println(this.hoursAlarm + " : " + this.minutesAlarm);

    }

    public void setClockAlarm(int hours, int minutes) {
        this.hoursAlarm = hours;
        this.minutesAlarm = minutes;
    }

    private void clockAlarm() {
        if (this.hoursAlarm == this.hours && this.minutesAlarm == this.minutes && this.seconds == 0) {
            new Thread(new Runnable() {
                public void run() {
                    try {
                        JOptionPane.showMessageDialog(null,"ACORDA PRINCESA!!!");
                    } catch (Exception e) {
                        System.out.println("Não foi possível executar a mensagem!");
                        System.exit(0);
                    }
                }
            }).start();
        }
    }

}
