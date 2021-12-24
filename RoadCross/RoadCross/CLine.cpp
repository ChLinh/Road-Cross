#include "CLine.h"
Line::Line()
{
	width = Right_Board_Game - Left_Board_Game + 1;
}
Line::Line(COORD coord, vector<Object*> v, bool thedir, short SleepTime)
{
	obj = v;
	pos = coord;
	dir = thedir;
	height = obj[0]->Height() + 1;
	width = Right_Board_Game - Left_Board_Game + 1;
	sleep = SleepTime;
	timeCount = 0;
	if (v[0]->GetShape() != dinos && v[0]->GetShape() != birds)
		stop = new StopLight(SleepTime, rand() % 2);
	else
		stop = nullptr;
}

void Line::Located()
{
	if (!obj.empty()) {
		for (int i = 0; i < obj.size(); i++) {
			delete obj[i];
			obj[i] = nullptr;
		}
		obj.clear();
	}
	delete stop;
	stop = nullptr;
}
bool Line::IsInside(const People& people)
{
	COORD peoplePos = (const_cast<People&>(people)).GetPos();
	if (pos.Y <= peoplePos.Y && peoplePos.Y < pos.Y + height)
		return true;
	return false;
}

COORD Line::GetPos()
{
	return pos;
}
void Line::Draw()
{
	int n = obj.size();

	if (dir == 0) {
		if (stop != nullptr)
			stop->Draw(this->pos.X, this->pos.Y);
		for (int i = 1; i < n; i++) {

			const short obj_left = obj[i]->GetPos().X;
			const short obj_right = obj[i]->GetPos().X + obj[i]->Width() - 1;
			if (Right_Board_Game > obj_left && Right_Board_Game < obj_right) {

				obj[0]->SetPos(Left_Board_Game - (Right_Board_Game - obj_left), obj[1]->GetPos().Y);
				for_each(obj.begin(), obj.end(), mem_fn(&Object::Draw));
				return;
			}
		}

		obj[0]->SetPos(0, 0);
		for_each(obj.begin() + 1, obj.end(), mem_fn(&Object::Draw));
	}
	else {
		if (stop != nullptr)
		{
			stop->Draw(this->pos.X + width - 3, this->pos.Y);
		}
		for (int i = 1; i < n; i++) {

			const short obj_left = obj[i]->GetPos().X;
			const short obj_right = obj[i]->GetPos().X + obj[i]->Width() - 1;

			if (Left_Board_Game > obj_left && Left_Board_Game < obj_right) {

				obj[0]->SetPos(Right_Board_Game - (Left_Board_Game - obj_left), obj[1]->GetPos().Y);
				for_each(obj.begin(), obj.end(), mem_fn(&Object::Draw));

				return;
			}
		}

		obj[0]->SetPos(0, 0);
		for_each(obj.begin() + 1, obj.end(), mem_fn(&Object::Draw));
	}
}
