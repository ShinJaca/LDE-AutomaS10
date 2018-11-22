/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servlets;

import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author murilo
 */
@WebServlet(name = "sistema", urlPatterns = {"/sistema"})
public class sistema extends HttpServlet {


    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        float total = Float.parseFloat(request.getParameter("L2"));
        
        Socket cliente = new Socket("127.0.0.1",12345);
        
        Scanner entrada = new Scanner(cliente.getInputStream());
        PrintStream saida = new PrintStream(cliente.getOutputStream());
        System.out.println("Primeiro dado enviado!");
        saida.println(String.valueOf(total));
        saida.flush(); 
        String resposta = entrada.nextLine();
        saida.close();
        entrada.close();
        cliente.close();
        String[] s = resposta.split(" ");
      request.setAttribute("Luz1", s[0]);
      request.setAttribute("Luz2", s[1]);
      request.getRequestDispatcher("computador.jsp").forward(request, response);
    }

}
