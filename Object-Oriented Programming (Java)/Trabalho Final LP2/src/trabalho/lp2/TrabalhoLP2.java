/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.lp2;

import Menu.Menus;
import Work.*;

/**
 *
 * Este trabalho implementa uma aplicação para gerir a repartição dos proveitos
 * de festivais de verão entre Artistas e seus Agentes
 *
 * @author Davide Barruncho 21104379
 * @author Yasmine Chede 21104555
 * @author Marta Dias 21103140
 */
public class TrabalhoLP2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        WPessoa.ler_Pessoa();
        WContracto.ler_Contracto();
        WContracto.verificar_contractos();
        WReparticao.ler_Reparticao();
        WEvento.ler_Evento();
        WReparticao.verificar_pagamentos();

        for (;;) {
            Menus.menu_principal();
        }
    }
}
