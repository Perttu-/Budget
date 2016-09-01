#include "databaseinterface.h"
#include <QDebug>
DatabaseInterface::DatabaseInterface(){}


QSqlError DatabaseInterface::initializeDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("budgetdatabase.db");

    if (!db.open()){
      qDebug() << "Db error";
      return db.lastError();
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS profile("
               "id          INTEGER         PRIMARY KEY AUTOINCREMENT, "
               "name        TEXT            NOT NULL,"
               "password    TEXT            NOT NULL)");

    query.exec("CREATE TABLE IF NOT EXISTS category("
               "id          INTEGER         PRIMARY KEY AUTOINCREMENT, "
               "name        TEXT            NOT NULL,"
               "isIncome    BOOLEAN         NOT NULL,"
               "description TEXT,"
               "dailyGoal   DECIMAL(10,2),"
               "weeklyGoal  DECIMAL(10,2),"
               "monthlyGoal DECIMAL(10,2),"
               "yearlyGoal  DECIMAL(10,2))");

    query.exec("CREATE TABLE IF NOT EXISTS transaction("
               "FOREIGN KEY(name)           REFERENCES category(name) ,"
               "id          INTEGER         PRIMARY KEY, "
               "timestamp   DATETIME        NOT NULL,"
               "amount      DECIMAL(10,2)   NOT NULL,"
               "FOREIGN KEY(profile)        REFERENCES profile(id) ON DELETE CASCADE"
               "comment     TEXT)");

    return QSqlError();
}


//Profile
void DatabaseInterface::addProfile(QString name, QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO profile(name, password)"
                  " VALUES(:name, :password)");
    query.bindValue(0, name);
    query.bindValue(1, password);
    query.exec();
}

void DatabaseInterface::editProfile(){}

void DatabaseInterface::deleteProfile(){}

//Category
void DatabaseInterface::addCategory(QString name, bool isIncome, QString description,
                                    float dailyGoal, float weeklyGoal, float yearlyGoal)
{
    QSqlQuery query;
    query.prepare("INSERT INTO category(name, isIncome, description, dailyGoal, weeklyGoal, yearlyGoal)"
                  "VALUES(:name, :isIncome, :description, :dailyGoal, :weeklyGoal, :yearlyGoal)");
    query.bindValue(0, name);
    query.bindValue(1, isIncome);
    query.bindValue(1, description);
    query.bindValue(1, dailyGoal);
    query.bindValue(1, weeklyGoal);
    query.bindValue(1, yearlyGoal);


}

void DatabaseInterface::editCategory(){}

void DatabaseInterface::deleteCategory(){}

//Transaction
void DatabaseInterface::addTransaction(){}

void DatabaseInterface::editTransaction(){}

void DatabaseInterface::deleteTransaction(){}




