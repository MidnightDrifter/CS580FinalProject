/* Copyright Steve Rabin, 2008. 
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright Steve Rabin, 2008"
 */

#pragma once



class GameObject;


typedef std::list<D3DXVECTOR3> WaypointList;

enum MovementMode
{
	MOVEMENT_NULL,
	MOVEMENT_SEEK_TARGET,
	MOVEMENT_WAYPOINT_LIST
};


class Movement
{
public:
	 static int HV_DISTANCE;
	static float DIAG_DISTANCE;
	Movement( GameObject& owner );
	~Movement( void );

	inline void SetTarget( D3DXVECTOR3& target )			{ m_target = target; }
	inline D3DXVECTOR3& GetTarget( void )					{ return( m_target ); }

	void Animate( double dTimeDelta );
	void DrawDebugVisualization( IDirect3DDevice9* pd3dDevice, D3DXMATRIX* pViewProj );

	void SetIdleSpeed( void );
	void SetWalkSpeed( void );
	void SetJogSpeed( void );

	bool ComputePathWithTiming( int r, int c, bool newRequest );
	void SetHeuristicWeight( float value )					{ m_heuristicWeight = value; }
    float GetHeuristicWeight() const                        { return m_heuristicWeight; }
	void SetHeuristicCalc( int value )						{ m_heuristicCalc = value; }
    int GetHeuristicCalc() const                            { return m_heuristicCalc; }
	void SetSmoothPath( bool enable )						{ m_smooth = enable; }
    bool GetSmoothPath() const                              { return m_smooth; }
	void SetRubberbandPath( bool enable )					{ m_rubberband = enable; }
    bool GetRubberbandPath() const                          { return m_rubberband; }
	void SetStraightlinePath( bool enable )					{ m_straightline = enable; }
    bool GetStraightlinePath() const                        { return m_straightline; }
	void SetSingleStep( bool enable )					    { m_singleStep = enable; }
    bool GetSingleStep() const                              { return m_singleStep; }
	void SetExtraCredit( bool enable )						    { m_extracredit = enable; }
	bool GetExtraCredit()									    { return m_extracredit; }
	void AStarUsesAnalysis( bool enable )					{ m_aStarUsesAnalysis = enable; }
    bool GetAnalysis() const                                { return m_aStarUsesAnalysis; }
    void SetFogOfWar( bool enable )                         { m_fogOfWar = enable; }
    bool GetFogOfWar() const                                { return m_fogOfWar; }

	


protected:

	GameObject* m_owner;

	bool m_smooth;
	bool m_rubberband;
	bool m_straightline;
	bool m_singleStep;
	bool m_extracredit;
	bool m_aStarUsesAnalysis;
    bool m_fogOfWar;
	float m_heuristicWeight;
	int m_heuristicCalc;
	MovementMode m_movementMode;

	D3DXVECTOR3 m_target;
	D3DXVECTOR3 m_goal;

	WaypointList m_waypointList;

	float m_speedWalk;
	float m_speedJog;

	bool ComputePath( int r, int c, bool newRequest );

	
	


};