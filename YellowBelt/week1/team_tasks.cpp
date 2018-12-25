class TeamTasks {
private:
	map<string, TasksInfo> team_tasks;
public:
	// ѕолучить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return team_tasks.at(person);
	}

	// ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
	void AddNewTask(const string& person) {
		team_tasks[person][TaskStatus::NEW]++;
	}

	// ќбновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		auto& person_tasks = team_tasks[person];
		int count = task_count;
		TasksInfo updated_tasks, untouched_tasks;
		for(int i = 0; i < static_cast<int>(TaskStatus::DONE); i++) {
			//Calculate updated tasks count in this status
			int updated_count = (count > person_tasks[TaskStatus(i)]) ? person_tasks[TaskStatus(i)] : count;
			count -= updated_count; //Update count

			if(updated_count > 0) {
				person_tasks[TaskStatus(i)] -= updated_count;
				updated_tasks[TaskStatus(i+1)] = updated_count;
			}
			if(person_tasks[TaskStatus(i)] > 0) {
				untouched_tasks[TaskStatus(i)] = person_tasks[TaskStatus(i)];
			}
		}
		for(int i = 0; i <= static_cast<int>(TaskStatus::DONE); i++) {
			person_tasks[TaskStatus(i)] += updated_tasks[TaskStatus(i)];
		}

		return make_tuple(updated_tasks, untouched_tasks);
	}
};