import json
import os
import sys

'''
读文件的函数
返回字典列表
'''
def readFileToList():
    # 从文件中获取商品列表字典对象
    fp = open('player.json', 'r', encoding='utf8')

    # 从文件中读取数据并转换为字典列表集合
    listplayer = json.load(fp)
    fp.close()
    return listplayer

'''
写文件的函数writeListToFile():
'''
def writeListToFile(listplayer:list):
    # 获取要操作的文件对象
    fp = open('player.json', 'w', encoding='utf8')

    json.dump(listplayer,fp,ensure_ascii=False)
    fp.flush()
    fp.close()
    pass


'''
定义Menu()菜单函数显示系统所有功能
'''
def Menu():

    print('=============玩家信息管理系统=============')
    print('-'*40)
    print('\t\t  1.录入玩家信息')
    print('\t\t  2.修改玩家信息')
    print('\t\t  3.查找玩家信息')
    print('\t\t  4.删除玩家信息')
    print('\t\t  5.显示玩家信息')
    print('\t\t  0.退出管理系统')
    print('-' * 40)

    pass


'''
定义addPlayer()函数录入玩家信息

定义玩家player，组成如下：
id--玩家编号（判断编号是否存在）
name--玩家昵称（判断昵称是否存在）
email--玩家邮箱（判断格式是否正确）
time--玩家注册游戏时间（判断格式是否正确）
levels--玩家生存等级（判断格式是否正确）
levelz--玩家战斗等级（判断格式是否正确）

将玩家信息添加至json文件中
'''
def addPlayer():

    #从文件中获取文件列表对象
    listplayer=readFileToList()

    #输入玩家信息
    player={}
    id = input('请输入玩家编号:')
    # 判断玩家id是否录入
    al = 0
    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        player['id'] = id
        al = 1

    while al == 0:
        # 玩家信息索引值
        index = -1
        # 根据id查询玩家信息是否存在，如果存在返回索引位置给index
        for i, players in enumerate(listplayer):
            if players['id'] == id:
                index = i
                id = input('该编号已存在，请重新输入：')
                break
        if index == -1:
            player['id'] = id
            al = 1


    name = input('请输入玩家昵称:')

    # 判断玩家昵称是否录入
    al = 0
    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        player['name'] = name
        al = 1

    while al == 0:
        # 玩家信息索引值
        index = -1
        # 根据昵称查询玩家信息是否存在，如果存在返回索引位置给index
        for i, players in enumerate(listplayer):
            if players['name'] == name:
                index = i
                name = input('该昵称已存在，请重新输入：')
                break
        if index == -1:
            player['name'] = name
            al = 1

    player['email'] = input('请输入玩家邮箱:')
    while '@' not in player['email'] or '.' not in player['email']:
        player['email'] = input('邮箱格式错误！请输入格式正确的邮箱地址:')

    player['time'] = input('请输入玩家注册游戏时间（如2000-01-01）:')
    while '-' not in player['time']:
        player['time'] = input('时间错误！请输入格式正确的注册时间（如2000-01-01）:')

    player['levels'] = input('请输入玩家生存等级（0-100）:')
    while int(player['levels']) < 0 or int(player['levels']) > 100:
        player['levels'] = input('生存等级错误！请输入0-100之间的整数：')

    player['levelz'] = input('请输入玩家战斗等级（0-100）:')
    while int(player['levelz']) < 0 or int(player['levelz']) > 100:
        player['levelz'] = input('战斗等级错误！请输入0-100之间的整数：')

    listplayer.append(player)
    writeListToFile(listplayer)#调用写列表到文件的函数

    print('玩家信息录入成功！\n')

    pass


'''
定义modifyPlayer()函数修改玩家信息
注意：只有昵称，邮箱和游戏等级可以修改，玩家编号和注册时间是不变的
'''
def modifyPlayer():
    # 从文件中读取字典列表
    listplayer = readFileToList()

    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        print('没有玩家信息！！！\n')
        return

    # 存放玩家信息的索引值
    index = -1

    name = input('请输入要修改的玩家昵称：')

    # 根据昵称查询玩家信息是否存在，如果存在返回索引位置给index
    for i, player in enumerate(listplayer):
        if player['name'] == name:
            index = i
            break

    if index != -1:
        player=listplayer[index]
        print('您要修改的玩家信息为:')
        print('%s\t\t    %s\t\t    %s\t\t    %s\t\t    %s\t\t    %s'
              % (player['id'], player['name'], player['email'], player['time'], player['levels'], player['levelz']))

        print('*****1.昵称 2.邮箱 3.生存等级 4.战斗等级 5.全部*****')
        choose = input('请输入您想要修改信息的对应数字：')
        if choose == '1':
            name = input('请输入玩家昵称:')
            al = 0
            if listplayer == None or len(listplayer) == 0:
                player['name'] = name
                al = 1
            while al == 0:
                index = -1
                for i, players in enumerate(listplayer):
                    if players['name'] == name:
                        index = i
                        name = input('该昵称已存在，请重新输入：')
                        break
                if index == -1:
                    player['name'] = name
                    al = 1
        if choose == '2':
            player['email'] = input('请输入玩家邮箱:')
            while '@' not in player['email'] or '.' not in player['email']:
                player['email'] = input('邮箱格式错误！请输入格式正确的邮箱地址:')
        if choose == '3':
            player['levels'] = input('请输入玩家生存等级（0-100）:')
            while int(player['levels']) < 0 or int(player['levels']) > 100:
                player['levels'] = input('生存等级错误！请输入0-100之间的整数：')
        if choose == '4':
            player['levelz'] = input('请输入玩家战斗等级（0-100）:')
            while int(player['levelz']) < 0 or int(player['levelz']) > 100:
                player['levelz'] = input('战斗等级错误！请输入0-100之间的整数：')
        if choose == '5':
            player['name'] = input('请输入新的玩家昵称:')
            player['email'] = input('请输入玩家邮箱:')
            while '@' not in player['email'] or '.' not in player['email']:
                player['email'] = input('邮箱格式错误！请输入格式正确的邮箱地址:')
            player['levels'] = input('请输入玩家生存等级（0-100）:')
            while int(player['levels']) < 0 or int(player['levels']) > 100:
                player['levels'] = input('生存等级错误！请输入0-100之间的整数：')
            player['levelz'] = input('请输入玩家战斗等级（0-100）:')
            while int(player['levelz']) < 0 or int(player['levelz']) > 100:
                player['levelz'] = input('战斗等级错误！请输入0-100之间的整数：')

        writeListToFile(listplayer)
        print('玩家信息修改成功！\n')
    else:
        print('该玩家不存在！！！\n')

    pass


'''
定义findPlayer()函数用昵称查找玩家信息
'''
def findPlayer():
    # 从文件中读取字典列表
    listplayer = readFileToList()

    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        print('没有玩家信息！！！')
        return

    # 存放玩家信息的索引值
    index = -1

    name = input('请输入要查询的玩家昵称：')

    # 根据昵称查询玩家信息是否存在，如果存在返回索引位置给index
    for i, player in enumerate(listplayer):
        if player['name'] == name:
            print('%s\t\t    %s\t\t    %s\t\t    %s\t\t    %s\t\t    %s\n'
                  % (player['id'], player['name'], player['email'], player['time'], player['levels'], player['levelz']))
            index = i
            break


    if index == -1:
        print('该昵称玩家不存在！！！\n')

    pass



'''
定义deletePlayer()函数删除玩家信息
'''
def deletePlayer():
    # 从文件中读取字典列表
    listplayer = readFileToList()

    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        print('没有玩家信息！！！')
        return

    # 存放玩家信息的索引值
    index = -1

    name = input('请输入要删除的玩家昵称：')

    # 根据昵称查询玩家信息是否存在，如果存在返回索引位置给index
    for i, player in enumerate(listplayer):
        if player['name'] == name:
            index = i
            break

    if index != -1:
        # 利用索引找到玩家信息并输出
        player = listplayer[index]
        print('您要删除的玩家信息为：')
        print('%s\t\t    %s\t\t    %s\t\t    %s\t\t    %s\t\t    %s'
              % (player['id'], player['name'], player['email'], player['time'], player['levels'], player['levelz']))

        # 将玩家信息从列表中删除
        listplayer.remove(player)
        # 将新的信息保存在文件中
        writeListToFile(listplayer)
        print('玩家删除成功！\n')
    else:
        print('该昵称玩家不存在！！！\n')

    pass


'''
定义函数showAllPlayer()
'''
def showAllPlayer():
    # 从文件中读取字典列表
    listplayer = readFileToList()

    # 判断是否有玩家信息
    if listplayer == None or len(listplayer) == 0:
        print('没有玩家信息！！！')
        return

    print('编号\t\t    昵称\t\t\t    邮箱\t\t\t    注册时间\t\t    生存等级\t\t    战斗等级')
    print('='*90)
    for player in listplayer:
        print('%s\t\t    %s    %s\t    %s\t\t    %s\t\t      %s'
              % (player['id'], player['name'], player['email'], player['time'], player['levels'], player['levelz']))
    print('=' * 90)
    print()

    pass


'''
定义main()函数与用户交互
利用while实现循环
'''
def main():
    while True:
        Menu()
        choose = input('请输入您选择的功能：')
        if choose == '1':
            print('玩家信息管理系统>>>录入信息>>>')
            addPlayer()
        if choose == '2':
            print('玩家信息管理系统>>>修改信息>>>')
            modifyPlayer()
        if choose == '3':
            print('玩家信息管理系统>>>查找信息>>>')
            findPlayer()
        if choose == '4':
            print('玩家信息管理系统>>>删除信息>>>')
            deletePlayer()
        if choose == '5':
            print('玩家信息管理系统>>>显示信息>>>')
            showAllPlayer()
        if choose == '0':
            print('感谢您的使用！')
            sys.exit(0)

    pass


if __name__ == '__main__':
    main()
    pass