import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * @brief Second step of the assignment : creating a frame with a 
 * Toolbar and a menubar with the same buttons as before
*/
public class Step3 {
   private JFrame mainFrame;
   private JTextArea testText;
   private JLabel headerLabel;
   private JToolBar toolBar;
   private JMenuBar menuBar;
   private JPanel controlPanel;
   private JLabel responseLabel;

   private JTextField fileEntry;
   private JTextField actionEntry;

   private Client client= null;
   private String status;
   static final String DEFAULT_HOST = "localhost";
   static final int DEFAULT_PORT = 3331;
   private static final long serialVersionUID = 1L;

   public static void main(String[] args){

      
      Step3 swingControlDemo = new Step3(); 
      swingControlDemo.connectClient(); 
      swingControlDemo.start();       
   }

   public Step3(){
      mainFrame = new JFrame("java swing GUI INF224 ");
      mainFrame.setSize(400,400);

      mainFrame.setLayout(new GridLayout(5,1));

      // creating header
      headerLabel = new JLabel("",JLabel.CENTER );
      

      //creating toolbar and menu bar
      toolBar = new JToolBar();  
      menuBar = new JMenuBar();

      // creating panel 
      controlPanel = new JPanel();
      controlPanel.setLayout(new FlowLayout());

      // adding label 
      responseLabel = new JLabel("");
      // creating scrollable text
      testText = new JTextArea("", 10, 1);
      JScrollPane scrollPane = new JScrollPane(testText);
      

      // adding components in order
      mainFrame.add(toolBar);
      mainFrame.add(headerLabel);
      mainFrame.add(controlPanel);
      mainFrame.add(responseLabel);
      mainFrame.add(scrollPane);

      // ensure window closes if break
      mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      // ending prog if window is closed
      mainFrame.addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent windowEvent){
            System.exit(0);
         }        
      });

      mainFrame.setVisible(true); 
   }

   private void connectClient(){
      // making connection 
         
      try {
         client = new Client(DEFAULT_HOST, DEFAULT_PORT);      
         status = "Client connected to "+DEFAULT_HOST+":"+DEFAULT_PORT;
      }
      catch (Exception e) {
         status = "Client: Couldn't connect to "+DEFAULT_HOST+":"+DEFAULT_PORT;
         System.exit(1);
      }

   }
   
   private void makeRequest(){
      try {
         String request = fileEntry.getText() + " " + actionEntry.getText();
         String response = client.send(request); //launching request
         testText.setText(response); // updating
         }
      catch (Exception a) {
         System.err.println("Client: error");
         System.err.println(a);
      }
   }

   private void start(){
      //setting labels
      headerLabel.setText(status); 
      responseLabel.setText("Response :");

      //creating buttons
      AbstractAction exitButton = new AbstractAction(){
         {
         putValue( Action.NAME, "exit" );
         }
         @Override public void actionPerformed(ActionEvent e){
            System.exit(0);
         }
      };
      
      AbstractAction sendButton = new AbstractAction(){
         {
         putValue( Action.NAME, "send" );
         }
         @Override public void actionPerformed(ActionEvent e){
            makeRequest();
         }
      };

      //updating and displaying menu bar
      JMenu commandsMenu = new JMenu( "Commands" );
      commandsMenu.add(sendButton);
      commandsMenu.add(exitButton);
      menuBar.add( commandsMenu );
      mainFrame.setJMenuBar(menuBar);  

      // updating tools bar
      toolBar.add(sendButton);
      toolBar.add(exitButton);

      JLabel actionText = new JLabel("Action :");
      actionEntry = new JTextField(7);

      JLabel fileText = new JLabel("File :");
      fileEntry = new JTextField(15);
      
      controlPanel.add(actionText);
      controlPanel.add(actionEntry);
      controlPanel.add(fileText);
      controlPanel.add(fileEntry);
      

      //mainFrame.pack();
      mainFrame.setVisible(true);  
   }
}