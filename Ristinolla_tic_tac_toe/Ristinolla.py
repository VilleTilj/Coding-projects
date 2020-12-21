# TIE-02101 Johdatus ohjelmointiin
# Teemu Mökkönen, teemu.mokkonen@tuni.fi (274561)
# Ville Tiljander, ville.tiljander@tuni.fi (274523)
# tkinter projekti, Ristinolla (Tick tack toe)
# This program is a small game called tick tack toe

from tkinter import *
from tkinter import messagebox

PLAYER_NUMBER = 2
mark = ["X", "O"]

class Userinterface:
    def __init__(self):
        """
        Constructor:
        Builds the game window (user interface)
        """
        # Launching read_me popup before mainwindow
        self.read_me()

        # Making the game window
        self.__mainwindow = Tk()
        self.__mainwindow.geometry("420x500")
        self.__mainwindow.title("Tick-tack-toe")

        # Creating infolabel objects to mainwindow
        self.__player1 = Label(self.__mainwindow)
        self.__player2 = Label(self.__mainwindow)
        self.__infolabel = Label(self.__mainwindow)

        self.__turn = 0
        self.__gamesituationtext = "Player " + str(self.__turn + 1) + " turn"
        self.__player_turn = [0] * PLAYER_NUMBER
        self.__linelabels = []
        self.__buttons = []
        self.__counter = 0
        self.__check = False
        self.__size = 3

        # Drawing the game board lines and adjusting the buttons in it and
        # disabling them and asking player names
        self.lines()
        self.squares()
        self.players()

        # Creating dropdown menu for gamerules and resetting the gameboard etc
        menu_bar = Menu(self.__mainwindow)
        self.__mainwindow.config(menu=menu_bar)
        Menu_toolbar = Menu(menu_bar)
        Menu_toolbar.add_command(label="New", command=self.start_over)
        Menu_toolbar.add_command(label="Rules", command=self.read_me)
        Menu_toolbar.add_command(label="About...", command=self.about)
        Menu_toolbar.add_command(label="Exit", command=self.stop)
        menu_bar.add_cascade(label="Options", menu=Menu_toolbar)

    def squares(self):
        """
        This method creates the buttons for the gameboard
        :return: None
        """
        number_button = 0
        y_cordinate = 0
        for j in range(self.__size):
            if j != 0:
                y_cordinate += 120

            x_cordinate = 0
            for i in range(self.__size):
                new_button = Button(self.__mainwindow, text="",
                                    command=lambda number=number_button:
                                    self.place_mark(number), state=DISABLED)
                new_button.place(x=25 + x_cordinate, y=115 + y_cordinate,
                                 width=120, height=115)

                self.__buttons.append(new_button)
                x_cordinate += 125
                number_button += 1

    def place_mark(self, button_number):
        """
        This method places "X" or "O" mark to a certain button and disables it
        :param button_number: wanted button to put the mark on
        :return: None
        """
        try:
            self.__buttons[button_number].configure(text="{}"
                                                    .format(mark[self.__turn]),font=('','40'),
                                                    state=DISABLED)
            self.__counter += 1
            self.check_winner()
            self.change_turn()
            self.__mainwindow.update()

        except:
            pass

    def disable_buttons(self):
        """
        This method disables all buttons
        :return: None
        """
        for i in range(len(self.__buttons)):
            self.__buttons[i].configure(state=DISABLED)

    def un_disable_buttons(self):
        """
        This method makes all the buttons normal again
        :return: None
        """
        for i in range(len(self.__buttons)):
            self.__buttons[i].configure(state=NORMAL)

    def check_winner(self):
        """
        This method check the game winner every turn
        :return:
        """
        j = 0
        k = 0
        x = 0
        try:
            for i in range(2):
                if self.__buttons[x]['text'] == mark[0] == self.__buttons[4]\
                    ['text'] and self.__buttons[8 - x]['text'] == mark[0]:
                    self.game_played()

                elif self.__buttons[x]['text'] == mark[1] == self.__buttons[4]\
                    ['text'] and self.__buttons[8 - x]['text'] == mark[i]:
                    self.game_played()

                else:
                    self.__check = True
                x += 2

            for i in range(3):
                if self.__buttons[j]['text'] == mark[0] == self.__buttons\
                    [j + 1]['text'] and \
                        self.__buttons[j + 2]['text'] == mark[0]:
                    self.game_played()

                elif self.__buttons[j]['text'] == mark[1] == self.__buttons\
                    [j + 1]['text'] and \
                    self.__buttons[j + 2]['text'] == mark[1]:
                    self.game_played()

                elif self.__buttons[k]['text'] == mark[0] == self.__buttons\
                    [k + 3]['text'] and \
                        self.__buttons[k + 6]['text'] == mark[0]:
                    self.game_played()

                elif self.__buttons[k]['text'] == mark[1] == self.__buttons\
                        [k + 3]['text'] and \
                        self.__buttons[k + 6]['text'] == mark[1]:
                    self.game_played()

                else:
                    self.__check = True
                k += 1
                j += 3

            if self.__check == True and self.__counter == 9:
                self.draw()
                self.__counter = 0
        except:
            pass

    def draw(self):
        """
        This method creates new popup when game is draw.
        :return: None
        """
        popup = Tk()
        popup.title("Game has ended")
        message = "Game has ended in a draw!\nStart a new game!"
        text = Label(popup, text=message)
        text.pack()
        button = Button(popup, command=popup.destroy, text='OK!')
        button.pack()
        popup.mainloop()

    def game_played(self):
        """
        This method creates new popup when player x wins
        :return: None
        """
        self.disable_buttons()
        popup = Tk()
        popup.title("Game has ended")
        message = "Player "+str(self.__turn + 1) +" has won the game!\n" \
                                                  "Start a new game!"
        text = Label(popup, text=message)
        text.pack()
        button = Button(popup, command=popup.destroy, text='OK!')
        button.pack()
        popup.mainloop()

    def players(self):
        """
        This method asks player names
        :return: None
        """
        self.__enter_players = Label(self.__mainwindow,
                                     bg='grey',
                                     text="   Enter player names!  "
                                          "\nPlayer one starts!")
        self.__enter_players.place(x=0, y=0, width=420, height=40)
        self.__player11 = Entry()
        self.__player11.place(x=0, y=40, width=420)
        self.__player12 = Entry()
        self.__player12.place(x=0, y=60, width=420)
        self.__button = Button(self.__mainwindow, text='Enter:',
                               command=self.player_names)
        self.__button.place(x=0, y=80, width=420)
        self.__gamesituationtext = "Player " + str(self.__turn + 1) + " turn"

    def player_names(self):
        """
        This method creates an error showbox if input of the name is wrong
        and if name is ok places them to the mainwindow
        :return: None
        """
        nimi1 = Entry.get(self.__player11)
        nimi2 = Entry.get(self.__player12)
        if nimi1 == "" or nimi2 == "":
            messagebox.showerror("Error", "You must enter name.")

        elif nimi1 != "" or nimi2 != "":
            self.__player1['text'] = "Player 1: {}".format(nimi1)
            self.__player2['text'] = "Player 2: {}".format(nimi2)
            self.__infolabel['text'] = self.__gamesituationtext
            self.__player1.place(x=100, y=60)
            self.__player2.place(x=250, y=60)
            self.__infolabel.place(x=170, y=480)
            self.__player11.destroy()
            self.__player12.destroy()
            self.__button.destroy()
            self.__enter_players.destroy()
            self.un_disable_buttons()

        else:
            messagebox.showerror("Error", "You must enter name.")

    def change_turn(self):
        """
        This method changes the turn and updates which players turn it is
        :return: None
        """
        try:
            self.__turn = (self.__turn + 1) % PLAYER_NUMBER
            self.__gamesituationtext = "Player "+str(self.__turn + 1) + " turn"
            self.__infolabel.configure(text=self.__gamesituationtext)
        except:
            pass

    def lines(self):
        """
        This method creates the black lines to the game board
        :return: None
        """
        j = 0
        for i in range(self.__size - 1):
            self.__label = Label(self.__mainwindow, background='black').place\
                (x=25, y=230+j, width=370, height=5)
            j += 120
        j = 0
        for i in range(self.__size - 1):
            self.__label = Label(self.__mainwindow, background='black').place\
                (x=145+j, y=115, width=5, height=355)
            j += 125

    def start_over(self):
        """
        Starts the game from the beginning and asks player names again
        :return: None
        """
        self.__player1.destroy()
        self.__player2.destroy()
        self.__infolabel.destroy()
        self.__player1 = Label(self.__mainwindow)
        self.__player2 = Label(self.__mainwindow)
        self.__infolabel = Label(self.__mainwindow)
        self.__turn = 0
        self.__buttons.clear()
        self.squares()
        self.disable_buttons()
        self.players()
        self.__counter = 0

    def about(self):
        """
        This method creates about popup that tells information about the
        project
        :return: None
        """
        about_popup = Tk()
        about_popup.title("Information about the project")
        message = "TIE-02100 Johdatus ohjelmointiin, Kevät 2019 \n" \
                  "TIE-02106 Introduction to Programming, spring 2019 \n" \
                  "The creators of the program: \n" \
                  "Ville Tiljander, ville.tiljander@tuni.fi, 274523 \n" \
                  "Teemu Mökkönen, teemu.mokkonen@tuni.fi, 274561 \n" \
                  "This program has been created for educational purposes!"
        text = Label(about_popup, text=message)
        text.pack()
        button = Button(about_popup, command=about_popup.destroy, text='OK!')
        button.pack()
        about_popup.mainloop()

    def stop(self):
        """
        This method stops the program
        :return: None
        """
        self.__mainwindow.destroy()

    def read_me(self):
        """
        This method creates read_me popup that tells the game rules
        :return: None
        """
        readme_popup = Tk()
        readme_popup.wm_title("READ ME!")
        msg = "Game rules!\n\n" \
              "The game is 3x3 tick tack toe game, where \nplayer 1 starts " \
              "with 'X' mark and player 2 uses mark 'O'.\n " \
              "You can reset, find information of the project and exit\nthe " \
              "program from the game from dropdown menu.\n\n " \
              "You have to give players names in ordes to play the game."
        label = Label(readme_popup, text=msg)
        label.pack()
        ok_button = Button(readme_popup, text="OK",
                           command=readme_popup.destroy)
        ok_button.pack()
        readme_popup.mainloop()
        pass

    def start(self):
        """
        Starts the mainloop.
        """
        self.__mainwindow.mainloop()


def main():
    ui = Userinterface()
    ui.start()


main()
