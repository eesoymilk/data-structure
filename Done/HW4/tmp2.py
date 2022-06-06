role = int(input())
if role != 1 and role != 2:
    print("role error")
else:
    score = int(input())
    score_to_pass = 60 if role == 1 else 70
    if score < 0 or score > 100:
        print("score error")
    elif score >= score_to_pass:
        print("pass")
    else:
        print("fail")
