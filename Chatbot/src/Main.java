import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import myclasses.ChatBot;

class BotWindow implements ActionListener {
    JFrame mainWin;
    ChatBot bot = new ChatBot();
    JTextArea botOutput;
    JTextField userInp;
    JButton prompt;
    JScrollPane botPrompt;
    BotWindow() {
        Border border = BorderFactory.createLineBorder(Color.BLACK);
        InputMap ip = new InputMap();

        // instantiating objects
        mainWin = new JFrame("Java Chatbot");
        prompt = new JButton("Enter");
        userInp = new JTextField();
        botOutput = new JTextArea();

        // setting properties for main window
        mainWin.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        mainWin.setSize(new Dimension(850, 600));
        mainWin.setLocation(370, 120);
        mainWin.setLayout(null);

        // setting botOutput screen
        botOutput.setBounds(new Rectangle(16, 10, 800, 470));
        botOutput.setBorder(BorderFactory.createCompoundBorder(border,
                BorderFactory.createEmptyBorder(5, 5, 5, 5)));
        botOutput.setEditable(false);
        botOutput.setLineWrap(true);
        botOutput.setWrapStyleWord(true);
        botOutput.setFont(new Font("Arial", Font.PLAIN, 15));
        botOutput.append("TR0N: Hello! I am TR0N, your virtual assistant!\n");
        // setting scroll pane
        botPrompt = new JScrollPane(botOutput);
        botPrompt.setBounds(new Rectangle(16, 10, 800, 470));
        // setting properties for user input
        userInp.setBounds(new Rectangle(20, 500, 700, 40));
        userInp.setFont(new Font("Poppins", Font.PLAIN, 15));
        userInp.setBorder(BorderFactory.createCompoundBorder(border,
                BorderFactory.createEmptyBorder(5, 5, 5, 5)));

        // setting properties for button
        prompt.setBounds(new Rectangle(740, 505, 70, 25));
        prompt.setFont(new Font("Poppins", Font.PLAIN, 12));
        prompt.setLayout(null);
        prompt.addActionListener(e -> {
            String inp = userInp.getText();
            String res = "";
            userInp.setText("");
            botOutput.append("\n");
            botOutput.append("You: "+ inp + "\n");
            try {
                res = bot.prompt(inp);
            } catch (Exception ex) {
                throw new RuntimeException(ex);
            }
            botOutput.append("\n");
            botOutput.append("TR0N: "+ res + "\n");
        });

        // adding components
        // mainWin.add(botOutput);
        mainWin.add(botPrompt);
        mainWin.add(userInp);
        mainWin.add(prompt);
        mainWin.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

    }
}

public class Main {
    public static void main(String[] args) {
        new BotWindow();
    }
}
