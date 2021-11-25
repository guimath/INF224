import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * @brief Second step of the assignment : creating a frame with a 
 * Toolbar and a menubar with the same buttons as before
*/
public class Step2 {
   private JFrame mainFrame;
   private JTextArea testText;
   private JLabel headerLabel;
   private JToolBar toolBar;
   private JMenuBar menuBar;

   private AbstractAction okButton;
   private AbstractAction wowButton;
   private AbstractAction exitButton;

   private static final long serialVersionUID = 1L;

   public static void main(String[] args){
      Step2 swingControlDemo = new Step2();  
      swingControlDemo.start();       
   }

   public Step2(){
      mainFrame = new JFrame("java swing GUI INF224 ");
      mainFrame.setSize(400,400);

      mainFrame.setLayout(new GridLayout(3,1));

      // creating header
      headerLabel = new JLabel("",JLabel.CENTER );
      
      // creating scrollable text
      testText = new JTextArea("", 10, 1);
      JScrollPane scrollPane = new JScrollPane(testText);
      
      //creating toolbar and menu bar
      toolBar = new JToolBar();  
      //toolBar.setRollover(true);  
      
      menuBar = new JMenuBar();

      // adding components in order
      mainFrame.add(toolBar);
      mainFrame.add(headerLabel);
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

   private void start(){
      headerLabel.setText("GUI : Testing step 2"); 

      okButton = new AbstractAction(){
         {
         putValue( Action.NAME, "OK" );
         }
         @Override public void actionPerformed(ActionEvent e){
            testText.append("OK\n");   
         }
      };
      wowButton = new AbstractAction(){
         {
         putValue( Action.NAME, "WOW" );
         }
         @Override public void actionPerformed(ActionEvent e){
            testText.append("WOW\n");   
         }
      };
      exitButton = new AbstractAction(){
         {
         putValue( Action.NAME, "exit" );
         }
         @Override public void actionPerformed(ActionEvent e){
            System.exit(0);
         }
      };
      
      //updating and displaying menu bar
      JMenu commandsMenu = new JMenu( "Commands" );
      commandsMenu.add(okButton);
      commandsMenu.add(wowButton);
      commandsMenu.add(exitButton);

      menuBar.add( commandsMenu );
      mainFrame.setJMenuBar(menuBar);  

      // updating tools bar
      toolBar.add(okButton); 
      toolBar.addSeparator(); 
      toolBar.add(wowButton);  
      toolBar.addSeparator(); 
      toolBar.add(exitButton);


      //mainFrame.pack();
      mainFrame.setVisible(true);  
   }
}