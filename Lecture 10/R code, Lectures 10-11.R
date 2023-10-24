#model 1: smoking and obesity
attach(hypertension)
model.hyper <- glm(hypnonhyp ~ smoking+obesity, binomial, data= hypertension)
summary(model.hyper)
step(model.hyper)

#model 2: obesity
model.hyper2 <- glm(hypnonhyp ~ obesity, binomial)
summary(model.hyper2)

#95% CI
confint(model.hyper)
confint.default(model.hyper)

#odds ratios, probabilities
coef(model.hyper)
exp(cbind('Odds ratio'=coef(model.hyper), confint(model.hyper)))

coef(model.hyper2)
exp(coef(model.hyper2))
exp(-1.676+0.76)
1/(1+exp(-(-1.676)))
1/(1+exp(-(-1.676+0.76)))

#menarche analysis

#model menarche
model.menar <- glm(menarche~age,binomial, data=menar)
summary(model.menar)
#predicted logits
predict(model.menar, type="response")
#probabilities
probs <- predict(model.menar, type="response")
probs
#probability plot
plot(probs~age, data=menar, pch=16, cex=0.7, type= "l",ylab="menarche")

#plot with frequencies by age
ageintervals <- cut(menar$age, c(8,9,10,11,12,13,14,15,16,17,18,19,20))
table1 <- table(ageintervals,menar$menarche)
table1
table2 <- prop.table(table1,1)[,2]
table2
points(table2 ~ c(8.5,9.5,10.5,11.5,12.5,13.5,14.5,15.5,16.5,17.5,18.5,19.5), 
       pch=1,cex=1.5)
#adding menarche by age
points(menarche ~ age, col='darkgrey', data=menar)

#factors with >2 levels
model.infant <- glm(healthy ~ month,binomial, data=infant)
summary(model.infant)
coef(model.infant)
exp(coef(model.infant))

levels(infant$month)
infant$month <- relevel(infant$month, ref = "6")
levels(infant$month) <- c("1", "2", "3", "4", "5", "6", "7", "8", "9")

#interactions
model.chd <- glm(chd~age*cat*chl,binomial, data=evans)
summary(model.chd)

#model optimisation
model.menar2 <- glm(menarche~age*igf1,binomial, data=menar)
summary(model.menar2)
step(model.menar2)
summary(step(model.menar2))


# exercises
model.igf1 <- glm(menarche~igf1,binomial, data=menar)
summary(model.igf1)
coef(model.igf1)
exp(coef(model.igf1))
#logit = a + b.X = log(odds at X)
-3.239608571 + 0.008646841*500
#odds at X = 500: exponentiate log(odds)
exp(1.083812)
#p = odds/ 1 + odds
2.955926/3.955926
#double checking with predict
predict(model.igf1 , data.frame (igf1 = 500), type="response")


model.chd2 <- glm(chd~age*cat,binomial, data=evans)
summary(model.chd2)
summary(step(model.chd2))

