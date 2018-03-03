import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListItemIcon, ListSubheader, ListItemText, ListItemSecondaryAction } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';
import ExpansionPanel, {
  ExpansionPanelDetails,
  ExpansionPanelSummary,
  ExpansionPanelActions,
} from 'material-ui/ExpansionPanel';
import Divider from 'material-ui/Divider';
import ExpandMoreIcon from 'material-ui-icons/ExpandMore';
import Select from 'material-ui/Select';
import { MenuItem } from 'material-ui/Menu';
import { FormControl, FormHelperText } from 'material-ui/Form';

import Profile from './_components/profile';
import UserStatus from './_components/userStatus';
import NoSpam from './_components/noSpam';
import StatusMessage from './_components/statusMessage';
import ToxAddress from './_components/toxAddress';
import DhtAddress from './_components/dhtAddress';
import UdpPort from './_components/udpPort';
import Toggle from './_components/toggle';

const styles = theme => ({
  profileSettingsBody: {
    height: 'calc(100vh - 80px)',
    overflow: 'auto',
  },
  profileSettingsContainer: {
    margin: '10px',
  },

  primaryText: {
    flex: 1,
    cursor: 'pointer',
  },
  panelList: {
    minWidth: '100px',
  }
});

class ProfileSettingsBody extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {
      profileOptionsPanelExpanded: false,
      toxOptionsPanelExpanded: false,
    };

    this._state = {
      settings: {
        nickname: props.settings.nickname,
        statusMessage: props.settings.statusMessage,
        userStatus: props.settings.userStatus,
        noSpam: props.settings.noSpam,
        avatarSrc: props.settings.avatarSrc,
        ipv6Enabled: props.settings.ipv6Enabled,
        udpEnabled: props.settings.udpEnabled,
        localDiscoveryEnabled: props.settings.localDiscoveryEnabled,
        holePunchingEnabled: props.settings.holePunchingEnabled,
      },
    };

    this.profileOptionsPanelExpanded = this.profileOptionsPanelExpanded.bind(this);
    this.toxOptionsPanelExpanded = this.toxOptionsPanelExpanded.bind(this);

    this.handleAvatarSrcChanged = this.handleAvatarSrcChanged.bind(this);
    this.handleNicknameChanged = this.handleNicknameChanged.bind(this);
    this.handleStatusMessageChanged = this.handleStatusMessageChanged.bind(this);
    this.handleUserStatusChanged = this.handleUserStatusChanged.bind(this);
    this.handleNoSpamChanged = this.handleNoSpamChanged.bind(this);
    
    this.handleIpv6ToggleChanged  = this.handleIpv6ToggleChanged.bind(this);
    this.handleUdpToggleChanged = this.handleUdpToggleChanged.bind(this);
    this.handleLocalDiscoveryToggleChanged = this.handleLocalDiscoveryToggleChanged.bind(this);
    this.handleHolePunchingToggleChanged = this.handleHolePunchingToggleChanged.bind(this);

    this.handleProfilePanelSaveClick = this.handleProfilePanelSaveClick.bind(this);
    this.handleToxOptionsPanelSaveClick = this.handleToxOptionsPanelSaveClick.bind(this);
  }

  profileOptionsPanelExpanded = function(event, expanded) {
    this.setState((prevState, props) => ({
      profileOptionsPanelExpanded: !prevState.profileOptionsPanelExpanded,
      toxOptionsPanelExpanded: prevState.toxOptionsPanelExpanded,      
    }));
  }

  toxOptionsPanelExpanded = function(event, expanded) {
    this.setState((prevState, props) => ({
      profileOptionsPanelExpanded: prevState.profileOptionsPanelExpanded,
      toxOptionsPanelExpanded: !prevState.toxOptionsPanelExpanded,
    }));
  }

  handleAvatarSrcChanged = function(newAvatarSrc) {
    this._state.settings.avatarSrc = newAvatarSrc;
  }

  handleNicknameChanged = function(newNickname) {
    this._state.settings.nickname = newNickname;
  }

  handleStatusMessageChanged = function(newStatus) {
    this._state.settings.statusMessage = newStatus;
  }

  handleUserStatusChanged = function(newStatus) {
    this._state.settings.userStatus = newStatus;
  }

  handleNoSpamChanged = function(newNoSpam) {

  }

  handleIpv6ToggleChanged = function(event, checked) {
    this._state.settings.ipv6Enabled = checked;
  }

  handleUdpToggleChanged = function(event, checked) {
    this._state.settings.udpEnabled = checked;
  }

  handleLocalDiscoveryToggleChanged = function(event, checked) {
    this._state.settings.localDiscoveryEnabled = checked;
  }

  handleHolePunchingToggleChanged = function(event, checked) {
    this._state.settings.holePunchingEnabled = checked;
  }

  handleProfilePanelSaveClick = function() {
    this.props.callbacks.profileOptionsCallback({
      nickname: this._state.settings.nickname,
      statusMessage: this._state.settings.statusMessage,
      userStatus: this._state.settings.userStatus,
      avatarSrc: this._state.settings.avatarSrc,
    });
  }

  handleToxOptionsPanelSaveClick = function() {
    this.props.callbacks.toxOptionsCallback({
      ipv6Enabled: this._state.settings.ipv6Enabled,
      udpEnabled: this._state.settings.udpEnabled,
      localDiscoveryEnabled: this._state.settings.localDiscoveryEnabled,
      holePunchingEnabled: this._state.settings.holePunchingEnabled,
    });
  }
   
  render() {
    return (    
      <Grid item className={ this.classes.profileSettingsBody }>
        <div className={ this.classes.profileSettingsContainer }>
          <ExpansionPanel 
            expanded={ this._state.profileOptionsPanelExpanded } 
            onChange={ this.profileOptionsPanelExpanded }
          >
            <ExpansionPanelSummary expandIcon={<ExpandMoreIcon/>}>
              <Typography variant="subheading">
                Profile
              </Typography>
            </ExpansionPanelSummary>
            <ExpansionPanelDetails>
              <List className={ this.classes.panelList }>
                <Profile
                  avatarSrc={ this._state.settings.avatarSrc }
                  avatarSrcCallback={ this.handleAvatarSrcChanged }
                  nickname={ this._state.settings.nickname }
                  nicknameCallback={ this.handleNicknameChanged }
                />
                <StatusMessage
                  statusMessage={ this._state.settings.statusMessage }
                  statusMessageCallback={ this.handleStatusMessageChanged }
                />
                <UserStatus
                  userStatus={ this._state.settings.userStatus }
                  userStatusCallback={ this.handleUserStatusChanged }
                />
                <ToxAddress
                  toxAddress={ this.props.settings.toxAddress }
                />
                <NoSpam
                  noSpam={ this.props.settings.noSpam }
                  noSpamCallback={ this.handleNoSpamChanged }
                />
                <DhtAddress
                  dhtAddress={ this.props.settings.dhtAddress }
                />
                <UdpPort
                  udpPort={ this.props.settings.udpPort }
                />
              </List>
            </ExpansionPanelDetails>
            <ExpansionPanelActions>              
              <Button 
                color="primary"
                onClick={ this.handleProfilePanelSaveClick }
              >
                Save
              </Button>
            </ExpansionPanelActions>
          </ExpansionPanel>

          <ExpansionPanel 
            expanded={ this._state.toxOptionsPanelExpanded } 
            onChange={ this.toxOptionsPanelExpanded }
          >
            <ExpansionPanelSummary expandIcon={<ExpandMoreIcon />}>
              <Typography variant="subheading">
                Tox options
              </Typography>
            </ExpansionPanelSummary>
            <ExpansionPanelDetails>
              <List className={ this.classes.panelList }>
                <Toggle
                  primaryText="IPV6 Enabled"
                  checked={ this._state.settings.ipv6Enabled }
                  toggleCallback={ this.handleIpv6ToggleChanged }
                />
                <Toggle
                  primaryText="UDP Enabled"
                  checked={ this._state.settings.udpEnabled }
                  toggleCallback={ this.handleUdpToggleChanged }
                />
                <Toggle
                  primaryText="Local Discovery Enabled"
                  checked={ this._state.settings.localDiscoveryEnabled }
                  toggleCallback={ this.handleLocalDiscoveryToggleChanged }
                />
                <Toggle
                  primaryText="Hole Punching Enabled"
                  checked={ this._state.settings.holePunchingEnabled }
                  toggleCallback={ this.handleHolePunchingToggleChanged }
                />
              </List>
            </ExpansionPanelDetails>
            <ExpansionPanelActions>              
              <Button 
                color="primary"
                onClick={ this.handleToxOptionsPanelSaveClick }
              >
                Save
              </Button>
            </ExpansionPanelActions>
          </ExpansionPanel>
        </div>
      </Grid>
    );
  }
} 

ProfileSettingsBody.propTypes = {
  classes: PropTypes.object.isRequired,
  settings: PropTypes.shape({
    nickname: PropTypes.string,
    statusMessage: PropTypes.string,
    userStatus: PropTypes.number,
    toxAddress: PropTypes.string,
    dhtAddress: PropTypes.string,
    udpPort: PropTypes.number,
    profilePassword: PropTypes.string,
    avatarSrc: PropTypes.string,
    noSpam: PropTypes.number,
    ipv6Enabled: PropTypes.bool,
    udpEnabled: PropTypes.bool,
    localDiscoveryEnabled: PropTypes.bool,
    holePunchingEnabled: PropTypes.bool,
  }),
  callbacks: PropTypes.shape({
    profileOptionsCallback: PropTypes.func,
    toxOptionsCallback: PropTypes.func,
  }),
};

ProfileSettingsBody.defaultProps = {
  settings: {
    nickname: "Default nickname",
    statusMessage: "Default status message",
    userStatus: 0,
    toxAddress: "Default tox address",
    dhtAddress: "Default DHT address",
    udpPort: 0,
    noSpam: 0,
    profilePassword: "",
    avatarSrc: "",
    ipv6Enabled: false,
    udpEnabled: false,
    localDiscoveryEnabled: false,
    holePunchingEnabled: false,
  },
  // callbacks: {
  //   profileOptionsCallback: ((newOptions) => {}),
  //   toxOptionsCallback: ((newOptions) => {}),
  // },
};

export default withStyles(styles)(ProfileSettingsBody);
