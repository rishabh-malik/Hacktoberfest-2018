import discord
import time
from discord.ext import commands
from openpyxl import load_workbook

wb = load_workbook(filename='worksheet.xlsx')

# List sheets available
sheets = wb.get_sheet_names()
print(sheets)

# Load active sheet or named sheet
sheet = wb.active

ieins = sheet['A1'].value
izwei = sheet['B1'].value
idrei = sheet['C1'].value
ivier = sheet['D1'].value
ifunf = sheet['E1'].value
isechs = sheet['F1'].value
isieben = sheet['G1'].value
iacht = sheet['H1'].value
ineun = sheet['I1'].value
izehn = sheet['J1'].value
ielf = sheet['K1'].value

bot = commands.Bot(command_prefix='b', description="description")

@bot.event
async def on_ready():
    print('Logged in as')
    print(bot.user.name)
    print(bot.user.id)
    print('------')

@bot.command()
async def apps():
    """Combines all cells into a formatted messages in discord"""
    x = 64
    # x is the amount of applications to be formatted
    while x != 65:
        xe = sheet['A' + str(x)].value
        xz = sheet['B' + str(x)].value
        xd = sheet['C' + str(x)].value
        xv = sheet['D' + str(x)].value
        xf = sheet['E' + str(x)].value
        xs = sheet['F' + str(x)].value
        xsi = sheet['G' + str(x)].value
        xac = sheet['H' + str(x)].value
        xneu = sheet['I' + str(x)].value
        xzeh = sheet['J' + str(x)].value
        xelf = sheet['K' + str(x)].value
        await bot.say(
        "```" + str(izwei) + "``` \n" + str(xz) 
        + "\n ```" + str(idrei) + "``` \n" + str(xd)
        + "\n ```" + str(ivier) + "``` \n" + str(xv)
        + "\n ```" + str(ifunf) + "``` \n" + str(xf)
        )
        await bot.say(
        "\n ```" + str(isechs) + "``` \n" + str(xs)
        + "\n ```" + str(isieben) + "``` \n" + str(xsi)
        )
        await bot.say(
        "\n ```" + str(iacht) + "``` \n" + str(xac)
        + "\n ```" + str(ineun) + "``` \n" + str(xneu)
        )
        await bot.say(
        "\n ```" + str(izehn) + "``` \n" + str(xzeh)
        + "\n ```" + str(ielf) + "``` \n" + str(xelf)
        )
        await bot.say(
        "\n \n \n ============================================================================================== \n \n \n"
        )
        await bot.say("Im finished")
        time.sleep(15)
        x = x + 1

@bot.command()
async def votes():
    """Sends all Usernames into the chat"""
    xvotes = 2
    while xvotes != 64:
        await bot.say(sheet['B' + str(xvotes)].value)
        time.sleep(5)
        xvotes = xvotes + 1

bot.run("token")