import numpy as np
from sklearn import datasets, linear_model
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt

diabetes = datasets.load_diabetes()

# print(diabetes.keys())
diabetes_X = diabetes.data[:, np.newaxis, 2]
# diabetes_X = diabetes.data for +1 features
diabetes_Y = diabetes.target

# training and testing sets
diabetes_X_train = diabetes_X[:-30]
diabetes_X_test = diabetes_X[-30:]

diabetes_Y_train = diabetes_Y[:-30]
diabetes_Y_test = diabetes_Y[-30:]

# modelling
model = linear_model.LinearRegression()

# fitting
model.fit(diabetes_X_train, diabetes_Y_train)

# prediction = actual - predicted
diabetes_Y_predicted = model.predict(diabetes_X_test)

print(f"Mean squared error = {mean_squared_error(diabetes_Y_test, diabetes_Y_predicted)}")

# model coef = slope
weight = model.coef_
intercept = model.intercept_

print(f"Slope = {weight}")
print(f"Intercept = {intercept}")

# plotting with one label
plt.scatter(diabetes_X_test, diabetes_Y_test)
plt.plot(diabetes_X_test, diabetes_Y_predicted)
plt.show()
