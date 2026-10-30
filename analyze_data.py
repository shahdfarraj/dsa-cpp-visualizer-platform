import numpy as np
import pandas as pd
from scipy import stats

# 1. Simulation of Pre-Test and Post-Test Data (40 Students)
np.random.seed(42)

# Control Group (Traditional Learning) - 20 Students
pre_control = np.random.normal(loc=55, scale=8, size=20).clip(30, 100)
post_control = np.random.normal(loc=63, scale=9, size=20).clip(30, 100)

# Experimental Group (Using C++ Visualizer Platform) - 20 Students
pre_exp = np.random.normal(loc=54, scale=8, size=20).clip(30, 100)
post_exp = np.random.normal(loc=83, scale=7, size=20).clip(30, 100)

# 2. System Usability Scale (SUS) Scores Simulation (10 items, scaled 0-100)
sus_scores = np.random.normal(loc=82.5, scale=6, size=20).clip(50, 100)

# 3. Statistical Calculations
t_stat_exp, p_val_exp = stats.ttest_rel(post_exp, pre_exp)
t_stat_comp, p_val_comp = stats.ttest_ind(post_exp, post_control)

print("=" * 50)
print("       STATISTICAL ANALYSIS & STUDY RESULTS       ")
print("=" * 50)

print(f"\n1. EXPERIMENTAL GROUP PERFORMANCE:")
print(f"   - Pre-Test Mean  : {np.mean(pre_exp):.2f} (SD: {np.std(pre_exp):.2f})")
print(f"   - Post-Test Mean : {np.mean(post_exp):.2f} (SD: {np.std(post_exp):.2f})")
print(f"   - Paired t-test  : t = {t_stat_exp:.4f}, p = {p_val_exp:.4e}")

print(f"\n2. GROUP COMPARISON (Post-Test Experimental vs Control):")
print(f"   - Control Post-Test Mean      : {np.mean(post_control):.2f}")
print(f"   - Experimental Post-Test Mean : {np.mean(post_exp):.2f}")
print(f"   - Independent t-test          : t = {t_stat_comp:.4f}, p = {p_val_comp:.4e}")

print(f"\n3. SYSTEM USABILITY SCALE (SUS) EVALUATION:")
print(f"   - Mean SUS Score : {np.mean(sus_scores):.2f} / 100 (Grade A - Highly Acceptable)")

# Export Dataset to CSV
df_results = pd.DataFrame({
    'Student_ID': [f'EXP_{i+1:02d}' for i in range(20)],
    'Pre_Test': np.round(pre_exp, 1),
    'Post_Test': np.round(post_exp, 1),
    'SUS_Score': np.round(sus_scores, 1)
})
df_results.to_csv('study_dataset.csv', index=False)
print("\n[Dataset] Exported 'study_dataset.csv' successfully.")