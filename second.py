def addStaff(listemp:list):
    staff={}
    staff['id'] = input('输入员工编号:')
    staff['name'] = input('输入员工姓名:')
    staff['sex'] = input('输入员工性别:')
    staff['address'] = input('输入员工地址:')
    staff['birthday'] = input('输入员工生日:')
    staff['salary'] = input('输入员工薪资:')

    listemp.append(staff)

    pass


def showInformation(listemp:list):
    if listemp == None or len(listemp) == 0:
        print('没有员工信息！！！')
        return

    print('编号\t\t  姓名\t\t 性别\t\t 地址\t\t 生日\t\t 薪资\t\t')
    print('=' * 90)
    for staff in listemp:
        print('%s\t\t  %s\t\t %s\t\t %s\t\t %s\t\t %s\t\t'
              %(staff['id'],staff['name'],staff['sex'],staff['address'],staff['birthday'],staff['salary']))
    print('=' * 90)

    pass


def findStaff(listemp:list):
    if listemp == None or len(listemp) == 0:
        print('没有员工信息存在！！！')
        return

    index = -1
    name = input('请输入要查找的员工姓名:')
    for i,staff in enumerate(listemp):
        if staff['name'] == name:
            index = i
            print('%s\t\t  %s\t\t %s\t\t %s\t\t %s\t\t %s\t\t'
                  % (staff['id'], staff['name'], staff['sex'], staff['address'], staff['birthday'], staff['salary']))

    if index == -1:
        print('未找到该员工信息！')

    pass


def deleteStaff(listemp:list):
    if listemp == None or len(listemp) == 0:
        print('没有员工信息存在！！！')
        return

    index = -1
    id=input('请输入要删除的员工编号:')
    for i,staff in enumerate(listemp):
        if staff['id'] == id:
            index = i
            break

    if index != -1:
        staff = listemp[index]
        print('%s\t\t  %s\t\t %s\t\t %s\t\t %s\t\t %s\t\t'
              % (staff['id'], staff['name'], staff['sex'], staff['address'], staff['birthday'], staff['salary']))

        listemp.remove(staff)
    else:
        print("未找到该员工信息！")

    pass


def updateStaff(listemp:list):
    if listemp == None or len(listemp) == 0:
        print('没有员工信息！！！')
        return

    index = -1
    id = input('请输入要修改的员工编号:')
    for i,staff in enumerate(listemp):
        if staff['id'] == id:
            index = i
            break

    if index != -1:
        staff=listemp[index]
        print('%s\t\t  %s\t\t %s\t\t %s\t\t %s\t\t %s\t\t'
              % (staff['id'], staff['name'], staff['sex'], staff['address'], staff['birthday'], staff['salary']))
        print('请输入新的员工信息：')
        staff['address'] = input('输入员工地址:')
        staff['salary'] = input('输入员工薪资:')
    else:
        print("未找到该员工信息！")

    pass


if __name__ == '__main__':
    listemp=[]
    while True:
        addStaff(listemp)
        choose = input('是否继续添加员工信息：继续--1，停止--0：')
        if choose == '0':
            break
        if choose == '1':
            continue

    showInformation(listemp)
    print()

    findStaff(listemp)
    print()

    deleteStaff(listemp)
    showInformation(listemp)
    print()

    while True:
        updateStaff(listemp)
        choose = input('是否继续修改：继续--1，停止--0：')
        if choose == '0':
            break
        if choose == '1':
            continue
    showInformation(listemp)