/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaces;

import enums.PessoaTipo;

/**
 * @author Davide Barruncho 21104379
 * @author Yasmine Chede 21104555
 * @author Marta Dias 21103140
 */
public interface IPessoa {

    /**
     *
     * @return
     */
    PessoaTipo getPessoaTipo();

    /**
     *
     * @return
     */
    String getNome();

    /**
     *
     * @param nome
     */
    void setNome(String nome);

    /**
     *
     * @return
     */
    String getApelido();

    /**
     *
     * @param apelido
     */
    void setApelido(String apelido);

    /**
     *
     * @return
     */
    long getNif();

    /**
     *
     * @return
     */
    long getID();

    /**
     *
     * @param id
     */
    void setID(long id);

    /**
     *
     * @param nif
     */
    void setNif(long nif);

    /**
     *
     * @return
     */
    double getCapital();

    /**
     *
     * @param capital
     */
    void setCapital(double capital);
    
}
