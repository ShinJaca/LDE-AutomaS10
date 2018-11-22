<%-- 
    Document   : computador
    Created on : Sep 29, 2018, 10:05:07 PM
    Author     : murilo
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Computador de Bordo</title>
    </head>
    <script>
       function mudarBotao(){
        var a = <%=request.getAttribute("total")%>;
        if (a === null)
            document.getElementById("botao").value = "clique para atualizar";
        else
            document.getElementById("botao").value = <%=request.getAttribute("total")%>;
    }
    </script>
    
    <body>
        <h1>Painel para controles das Luzes</h1>
        <form action="sistema" method="POST">
             <input type="hidden" size="10" value="<%=request.getAttribute("Luz1")%>" name="L1"/><br>
            <input type="submit" value="<%=request.getAttribute("Luz1")%>" />
           
        </form>
        <form action="sistema" method="POST">
             <input type="hidden" size="10" value="<%=request.getAttribute("Luz2")%>" name="L2"/><br>
             <input type="submit" value="<%=request.getAttribute("Luz2")%>" />
        </form>
    </body>
</html>
