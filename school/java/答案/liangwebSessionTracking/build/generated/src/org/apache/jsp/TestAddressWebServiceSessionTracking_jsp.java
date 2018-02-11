package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import chapter41.Address;
import chapter41.AddressWebServiceSessionTracking;
import chapter41.AddressServiceSessionTracking;

public final class TestAddressWebServiceSessionTracking_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static java.util.Vector _jspx_dependants;

  private org.apache.jasper.runtime.ResourceInjector _jspx_resourceInjector;

  public java.util.List getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    JspFactory _jspxFactory = null;
    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;


    try {
      _jspxFactory = JspFactory.getDefaultFactory();
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      String resourceInjectorClassName = config.getInitParameter("com.sun.appserv.jsp.resource.injector");
      if (resourceInjectorClassName != null) {
        _jspx_resourceInjector = (org.apache.jasper.runtime.ResourceInjector) Class.forName(resourceInjectorClassName).newInstance();
        _jspx_resourceInjector.setContext(application);
      }

      out.write("<!-- TestAddressWebServiceSessionTracking.jsp -->\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      chapter41.Address addressId = null;
      synchronized (session) {
        addressId = (chapter41.Address) _jspx_page_context.getAttribute("addressId", PageContext.SESSION_SCOPE);
        if (addressId == null){
          addressId = new chapter41.Address();
          _jspx_page_context.setAttribute("addressId", addressId, PageContext.SESSION_SCOPE);
        }
      }
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.introspect(_jspx_page_context.findAttribute("addressId"), request);
      out.write("\n");
      out.write("\n");
      out.write("<html>\n");
      out.write("<head>\n");
      out.write("  <title>Address Information</title>\n");
      out.write("</head>\n");
      out.write("<body>    \n");
      out.write("  <form method = \"get\" \n");
      out.write("    action = \"TestAddressWebServiceSessionTracking.jsp\">\n");
      out.write("  Last Name <font color = \"#FF0000\">*</font>\n");
      out.write("  <input type = \"text\" name = \"lastName\"         \n");
      out.write("    ");
if (addressId.getLastName() != null) {
      out.print("value = \"" + addressId.getLastName() + "\"");}
      out.write("        \n");
      out.write("   size = \"20\" />&nbsp;\n");
      out.write("\n");
      out.write("  First Name <font color = \"#FF0000\">*</font>\n");
      out.write("  <input type = \"text\" name = \"firstName\"  \n");
      out.write("    ");
if (addressId.getFirstName() != null) {
      out.print("value = \"" + addressId.getFirstName() + "\"");}
      out.write("        \n");
      out.write("   size = \"20\" />&nbsp;\n");
      out.write("\n");
      out.write("  MI \n");
      out.write("  <input type = \"text\" name = \"mi\" \n");
      out.write("    ");
if (addressId.getMi() != null) {
      out.print("value = \"" + addressId.getMi() + "\" "); } 
      out.write("        \n");
      out.write("   size = \"3\" />&nbsp;\n");
      out.write("\n");
      out.write("  <p>Telephone \n");
      out.write("  <input type = \"text\" name = \"telephone\" \n");
      out.write("    ");
if (addressId.getTelephone() != null) {
      out.print("value = \"" + addressId.getTelephone() + "\" ");}
      out.write("        \n");
      out.write("   size = \"20\" />&nbsp;\n");
      out.write("\n");
      out.write("  Email \n");
      out.write("  <input type = \"text\" name = \"email\" \n");
      out.write("    ");
if (addressId.getEmail() != null) {
      out.print("value = \"" + addressId.getEmail() + "\" ");}
      out.write("        \n");
      out.write("   size = \"28\" />&nbsp;\n");
      out.write("  </p>\n");
      out.write("    \n");
      out.write("  <p>Street \n");
      out.write("  <input type = \"text\" name = \"street\"                          \n");
      out.write("    ");
if (addressId.getStreet() != null) {
      out.print("value = \"" + addressId.getStreet() + "\" ");}
      out.write("        \n");
      out.write("   size = \"50\" />&nbsp;    \n");
      out.write("  </p>\n");
      out.write("    \n");
      out.write("  <p>City \n");
      out.write("  <input type = \"text\" name = \"city\" \n");
      out.write("    ");
if (addressId.getCity() != null) {
      out.print("value = \"" + addressId.getCity() + "\" ");}
      out.write("        \n");
      out.write("  size = \"23\" />&nbsp;    \n");
      out.write("\n");
      out.write("  State \n");
      out.write("  <select size = \"1\" name = \"state\">\n");
      out.write("    <option value = \"GA\">Georgia-GA</option>\n");
      out.write("    <option value = \"OK\">Oklahoma-OK</option>\n");
      out.write("    <option value = \"IN\">Indiana-IN</option>\n");
      out.write("  </select>&nbsp;\n");
      out.write("  \n");
      out.write("  Zip \n");
      out.write("  <input type = \"text\" name = \"zip\"                    \n");
      out.write("    ");
if (addressId.getZip() != null) {
      out.print("value = \"" + addressId.getZip() + "\" "); } 
      out.write("        \n");
      out.write("   size = \"9\" />&nbsp;\n");
      out.write("  </p>\n");
      out.write("  \n");
      out.write("  <p><input type = \"submit\" name = \"Submit\" value = \"Search\">\n");
      out.write("     <input type = \"submit\" name = \"Submit\" value = \"Store\">\n");
      out.write("     <input type = \"reset\" value = \"Reset\">\n");
      out.write("  </p>\n");
      out.write("  </form>\n");
      out.write("  <p><font color = \"#FF0000\">* required fields</font></p>\n");
      out.write("\n");
      out.write("  ");
 
  if (request.getParameter("Submit") != null) {       
    AddressWebServiceSessionTracking addressWebService 
      = new AddressWebServiceSessionTracking();
    AddressServiceSessionTracking proxy 
      = addressWebService.getAddressServiceSessionTrackingPort();
    
    if (request.getParameter("Submit").equals("Store")) { 
      if (proxy.storeAddressInSession(addressId)) {
      out.write("\n");
      out.write("        ");
      if (true) {
        _jspx_page_context.forward("Confirm.jsp");
        return;
      }
      out.write("\n");
      out.write("  ");
 } else 
      out.println(addressId.getFirstName() + " " + 
        addressId.getLastName() + " is already in the database");
    } 
    else if (request.getParameter("Submit").equals("Search")) {
      Address address = proxy.getAddress(addressId.getFirstName(),
        addressId.getLastName());
      if (address == null)
        out.print(addressId.getFirstName() + " " +
          addressId.getLastName() + " is not in the database");
      else
        addressId = address;
    }
  }
  
      out.write("  \n");
      out.write("</body>\n");
      out.write("</html> \n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
      }
    } finally {
      if (_jspxFactory != null) _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
