/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servlets;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintStream;
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
@WebServlet(name = "computador", urlPatterns = {"/computador"})
public class computador extends HttpServlet {

   
 
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        float total = Float.parseFloat(request.getParameter("entrada"));
        //float preco = Float.parseFloat(request.getParameter("preco"));
        //float consumo = Float.parseFloat(request.getParameter("consumo"));
        //
        //float valor = total/preco;
        //float distancia = total*consumo;

        //request.setAttribute("valor", valor);
        request.setAttribute("Luz1", total);
        request.setAttribute("Luz2", total);
        
        
        
      /*  Socket cliente = new Socket("127.0.0.1",12345);
        
        Scanner entrada = new Scanner(cliente.getInputStream());
        PrintStream saida = new PrintStream(cliente.getOutputStream());
        System.out.println("Primeiro dado enviado!");
        saida.println("enviando");
        saida.flush(); 
        System.out.println(entrada.nextLine());
        saida.close();
        entrada.close();
        cliente.close();
         
         
        */
      request.getRequestDispatcher("computador.jsp").forward(request, response);
    }

  

}
