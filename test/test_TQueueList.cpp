#include "Queue.h"
#include <gtest.h>

TEST(TQueueList, can_create_QueueList)
{
  ASSERT_NO_THROW(TQueueList<int> qe);
}

TEST(TQueueList, create_empty_QueueList)
{
	TQueueList<int> qe;

	EXPECT_EQ(true, qe.IsEmpty());
}

TEST(TQueueList, create_isfull_QueueList)
{
	TQueueList<int> qe;

	EXPECT_EQ(false, qe.IsFull());
}

TEST(TQueueList, can_push)
{
	TQueueList<int> qe;

	ASSERT_NO_THROW(qe.Push(3));
}

TEST(TQueueList, can_get_elem)
{
	TQueueList<int> qe;
	qe.Push(5);

	EXPECT_EQ(5, qe.Get());
}

TEST(TQueueList, cant_get_if_empty)
{
	TQueueList<int> qe;

	ASSERT_ANY_THROW(qe.Get());
}

TEST(TQueueList, can_copy_QueueList)
{
	TQueueList<int> qe1;
	qe1.Push(1);

	ASSERT_NO_THROW(TQueueList<int> qe2(qe1));
}

TEST(TQueueList, can_assing_QueueList)
{
	TQueueList<int> qe1;
	qe1.Push(1);
	TQueueList<int> qe2;
	qe2 = qe1;

	EXPECT_EQ(1, qe2.Get());
}

TEST(TQueueList, can_get_count)
{
	TQueueList<int> qe;
	qe.Push(2);
	qe.Push(3);
	EXPECT_EQ(2, qe.GetCount());
}

TEST(TQueueList, DOP_can_save_in_file_DOP)
{
	TQueueList<int> qe;
	qe.Push(10);
	qe.Push(20);
	qe.Push(30);
	qe.Push(40);
	ASSERT_NO_THROW(qe.File());
}

TEST(TQueueList, DOP_can_get_max_elem_DOP)
{
	TQueueList<int> qe;
	qe.Push(1);
	qe.Push(72);
	qe.Push(4);
	qe.Push(10);
	qe.Push(54);
	qe.Push(9);
	EXPECT_EQ(72, qe.Max_elem());
}

TEST(TQueueList, DOP_can_get_min_elem_DOP)
{
	TQueueList<int> qe;
	qe.Push(1);
	qe.Push(72);
	qe.Push(4);
	qe.Push(10);
	qe.Push(54);
	qe.Push(9);
	EXPECT_EQ(1, qe.Min_elem());
}