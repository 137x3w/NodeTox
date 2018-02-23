import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import ProfileSettingsBody from './profileSettingsBody';
import FriendsControlView from './friendsControlView';
import GroupsControlView from './groupsControlView';

const styles = theme => ({
  dashboardBody: {
    height: 'calc(100vh - 80px)',
    overflow: 'auto',
  },
});

class DashboardBody extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (    
      <Grid item className={ this.classes.dashboardBody }>
        {
          (() => {
            switch(this.props.renderIndex) {
              case 0: return (
                <FriendsControlView
                  requests={ this.props.friendsControl.friendRequests }
                />
              )
              case 1: return (
                <GroupsControlView/>
              )
              case 4: return (
                <ProfileSettingsBody
                  nickname={ this.props.settings.nickname }
                  statusMessage={ this.props.settings.statusMessage }
                  toxid={ this.props.settings.toxid }
                  profilePassword={ this.props.settings.profilePassword }
                  avatarSrc={ this.props.settings.avatarSrc }
                />
              )
              default: return (
                <div></div>
              )
            }
          })()
        }
      </Grid>
    );
  }
} 

DashboardBody.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(DashboardBody);
